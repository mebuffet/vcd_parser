/*
 * Copyright (c) 2013-2013 Wei Song <songw@cs.man.ac.uk> 
 *    Advanced Processor Technologies Group, School of Computer Science
 *    University of Manchester, Manchester M13 9PL UK
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

/* 
 * Helper classes for the Value Change Dump (VCD) parser
 * 30/06/2013   Wei Song
 *
 *
 */

#include "vcd_util.hpp"
#include "vcd.hh"
#include <boost/lexical_cast.hpp>

using namespace vcd;
using std::string;

#define TType vcd_parser::token 

vcd::VCDLexer::VCDLexer(std::istream * i) 
  : istm(i), state(0) { }

int vcd::VCDLexer::lexer(vcd_token_type * rv) {
  while(true) {
    if(buf.empty()) {
      if(istm->eof()) return 0;
      else std::getline(*istm, buf);
    }

    //std::cout << "buf: " << buf;

    string token = next_token();
    if(token.empty()) continue;
    else {
      int rvt = validate_token(token, rv);
      //std::cout << " |token: " << rvt << std::endl;
      return rvt;
    }
  }
}

string vcd::VCDLexer::next_token() {
  // get rid of starting blanks
  buf.erase(0, buf.find_first_not_of(' '));
  if(buf.empty()) return buf;

  unsigned int loc = buf.find_first_of(' ');
  string t = buf.substr(0, loc);
  buf.erase(0, loc);
  return t;
}

int vcd::VCDLexer::validate_token(const string& t, vcd_token_type * tt) {
  switch(state) {
  case S_BEGIN: {
    if(t == "$comment")
      { state = S_COMMENT;        return TType::VCDComment;   }
    if(t == "$date")
      { state = S_COMMENT;        return TType::VCDDate;      }
    if(t == "$enddefinitions")    return TType::VCDEndDef;
    if(t == "$scope")     
      { state = S_SCOPE_DECL;     return TType::VCDScope;     }
    if(t == "$timescale") 
      { state = S_TIMESCALE_DECL; return TType::VCDTimeScale; }
    if(t == "$upscope")           return TType::VCDUpScope;
    if(t == "$var")       
      { state = S_VAR_DECL;       return TType::VCDVar;       }
    if(t == "$version")
      { state = S_COMMENT;        return TType::VCDVersion;   }
    if(t == "$dumpall")   
      { state = S_BEGIN; tt->tType = sim_all;  return TType::VCDSimCmdType;  }
    if(t == "$dumpoff")   
      { state = S_BEGIN; tt->tType = sim_off;  return TType::VCDSimCmdType;  }
    if(t == "$dumpon")    
      { state = S_BEGIN; tt->tType = sim_on;   return TType::VCDSimCmdType;  }
    if(t == "$dumpvars")  
      { state = S_BEGIN; tt->tType = sim_vars; return TType::VCDSimCmdType;  }
    if(t[0] == '#')       
      { state = S_SIM_TIME; buf.insert(0, t, 1, t.size()-1); return '#'; }
    if(t[0] == '0' || t[0] == '1') {
      state = S_VALUE_CHANGE_SCALAR; 
      buf.insert(0, t, 1, t.size()-1); 
      tt->tValue = t[0];
      return TType::VCDValue;
    }
    if(t[0] == 'x' || t[0] == 'X') {
      state = S_VALUE_CHANGE_SCALAR; 
      buf.insert(0, t, 1, t.size()-1); 
      tt->tValue = 'x';
      return TType::VCDValue;
    }
    if(t[0] == 'z' || t[0] == 'Z') {
      state = S_VALUE_CHANGE_SCALAR; 
      buf.insert(0, t, 1, t.size()-1); 
      tt->tValue = 'z';
      return TType::VCDValue;
    }
    if(t[0] == 'b' || t[0] == 'B') {
      state = S_VALUE_CHANGE_VB;
      buf.insert(0, t, 1, t.size()-1); 
      return 'b';
    }
    if(t[0] == 'r' || t[0] == 'R') {
      state = S_VALUE_CHANGE_VR;
      buf.insert(0, t, 1, t.size()-1); 
      return 'r';
    }
    if(t == "$end")  return TType::VCDEnd;
    tt->tStr = t;
    return TType::VCDStr;
  }
  case S_COMMENT: {
    if(t == "$end") {
      state = S_BEGIN;
      return TType::VCDEnd;
    }
    tt->tStr = t;
    return TType::VCDStr;
  }
  case S_SCOPE_DECL: {
    if(t == "begin")    
      { tt->tType = scope_begin;    state = S_SCOPE_TYPE; return TType::VCDScopeType; }
    if(t == "fork")     
      { tt->tType = scope_fork;     state = S_SCOPE_TYPE; return TType::VCDScopeType; }
    if(t == "function") 
      { tt->tType = scope_function; state = S_SCOPE_TYPE; return TType::VCDScopeType; }
    if(t == "module")   
      { tt->tType = scope_module;   state = S_SCOPE_TYPE; return TType::VCDScopeType; }
    if(t == "task")     
      { tt->tType = scope_task;     state = S_SCOPE_TYPE; return TType::VCDScopeType; }
    
    assert(0 == "wrong scope type");
    state = S_BEGIN;
    return conv_to_string(t, tt);
  }    
  case S_SCOPE_TYPE: {
    state = S_BEGIN;
    return conv_to_string(t, tt);
  }    
  case S_TIMESCALE_DECL: {
    int rt = conv_to_dec(t, tt);
    if(rt == TType::VCDNum) state = S_TIMESCALE_TIME;
    else                         state = S_BEGIN;
    return rt;
  }
  case S_TIMESCALE_TIME: {
    if(t == "s")  { tt->tType = time_s;   state = S_BEGIN; return TType::VCDTimeUnit; }
    if(t == "ms") { tt->tType = time_ms;  state = S_BEGIN; return TType::VCDTimeUnit; }
    if(t == "us") { tt->tType = time_us;  state = S_BEGIN; return TType::VCDTimeUnit; }
    if(t == "ns") { tt->tType = time_ns;  state = S_BEGIN; return TType::VCDTimeUnit; }
    if(t == "ps") { tt->tType = time_ps;  state = S_BEGIN; return TType::VCDTimeUnit; }
    if(t == "fs") { tt->tType = time_fs;  state = S_BEGIN; return TType::VCDTimeUnit; }
    
    assert(0 == "wrong time unit");
    state = S_BEGIN;
    return conv_to_string(t, tt);
  }
  case S_VAR_DECL: {
    if(t == "event")     
      { tt->tType = var_event;     state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "integer")   
      { tt->tType = var_integer;   state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "parameter") 
      { tt->tType = var_parameter; state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "real")      
      { tt->tType = var_real;      state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "reg")       
      { tt->tType = var_reg;       state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "supply0")   
      { tt->tType = var_supply0;   state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "supply1")   
      { tt->tType = var_supply1;   state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "time")      
      { tt->tType = var_time;      state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "tri")       
      { tt->tType = var_tri;       state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "triand")    
      { tt->tType = var_triand;    state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "trior")     
      { tt->tType = var_trior;     state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "trireg")    
      { tt->tType = var_trireg;    state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "tri0")      
      { tt->tType = var_tri0;      state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "tri1")      
      { tt->tType = var_tri1;      state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "wand")      
      { tt->tType = var_wand;      state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "wire")      
      { tt->tType = var_wire;      state = S_VAR_TYPE; return TType::VCDVarType; }
    if(t == "wor")       
      { tt->tType = var_wor;       state = S_VAR_TYPE; return TType::VCDVarType; }
    
    assert(0 == "wrong variable type");
    state = S_BEGIN;
    return conv_to_string(t, tt); 
  }
  case S_VAR_TYPE: {
    int rt = conv_to_dec(t, tt);
    if(rt == TType::VCDNum) state = S_VAR_WIDTH;
    else                         state = S_BEGIN;
    return rt;    
  }
  case S_VAR_WIDTH: {
    state = S_VAR_ID;
    return conv_to_string(t, tt);
  }
  case S_VAR_ID: {
    state = S_VAR_CID;
    return conv_to_string(t, tt);
  }
  case S_VAR_CID: {
    if(t == "$end") { state = S_BEGIN; return TType::VCDEnd; }
    if(t[0] == '[') {
      state = S_VAR_RANGE;
      buf.insert(0, t, 1, t.size()-1); 
      return '[';      
    }

    assert(0 == "wrong reference format");
    state = S_BEGIN;
    return conv_to_string(t, tt);     
  }
  case S_VAR_RANGE: {
    if(t[0] == ':') { buf.insert(0, t, 1, t.size()-1); return ':'; }
    if(t[0] == ']') { state = S_VAR_CID; buf.insert(0, t, 1, t.size()-1); return ']'; }
    int rt = conv_to_dec(t, tt);
    if(rt != TType::VCDNum) state = S_BEGIN;
    return rt;
  }
  case S_SIM_TIME: {
    state = S_BEGIN;
    return conv_to_dec(t, tt);        
  } 
  case S_VALUE_CHANGE_SCALAR: {
    state = S_BEGIN;
    return conv_to_string(t, tt);
  }
  case S_VALUE_CHANGE_VB: {
    state = S_VALUE_CHANGE_ID;
    tt->tBValue = t;
    return TType::VCDBValue;
  }    
  case S_VALUE_CHANGE_VR: {
    state = S_VALUE_CHANGE_ID;
    return conv_to_real(t, tt);
  }
  case S_VALUE_CHANGE_ID: {
    state = S_BEGIN;
    return conv_to_string(t, tt);
  }
  default:
    assert(0 == "wrong lexer state");
    return 0;
  }
}

int vcd::VCDLexer::conv_to_string(const string& t, vcd_token_type * tt) {
  tt->tStr = t;
  return TType::VCDStr;
}

int vcd::VCDLexer::conv_to_dec(const string& t, vcd_token_type * tt) {
  try {
    unsigned int pos = t.find_first_not_of("0123456789");
    string nstring = t;
    if(pos < t.size()) {
      nstring = t.substr(0, pos);
      buf.insert(0, t, pos, t.size()-1);
    }
    tt->tNum = nstring;
    return TType::VCDNum;
  } catch(std::invalid_argument &) {
    assert(0 == "unrecognizable decimal number");
    tt->tStr = t;
    return TType::VCDStr;
  }
}

int vcd::VCDLexer::conv_to_real(const string& t, vcd_token_type * tt) {
  try {
    unsigned int pos = t.find_first_not_of("0123456789.");
    string nstring = t;
    if(pos < t.size()) {
      nstring = t.substr(0, pos);
      buf.insert(0, t, pos, t.size()-1);
    }
    tt->tReal = boost::lexical_cast<double>(nstring);
    return TType::VCDReal;
  } catch(boost::bad_lexical_cast &) {
    assert(0 == "unrecognizable real number");
    tt->tStr = t;
    return TType::VCDStr;
  }
}


string vcd::timeunit_stype(int t) {
  switch(t) {
  case time_s:  return "s";
  case time_ms: return "ms";
  case time_us: return "us";
  case time_ns: return "ns";
  case time_ps: return "ps";
  case time_fs: return "fs";
  default: assert(0 == "wrong time unit type!");
    return "ns";
  }
}
