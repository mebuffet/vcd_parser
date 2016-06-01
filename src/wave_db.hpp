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
 * A waveform data base
 * 01/07/2013   Wei Song
 *
 *
 */

#ifndef WAVE_DB_H_
#define WAVE_DB_H_

#include <string>
#include <map>
#include <vector>
#include <gmpxx.h>
#include <cassert>
#include <iostream>
#include <sstream>
#include "crange.hpp"

namespace vcd {

  enum _report_style
  {
      STRING,
      RVALUE
  };

  typedef enum _report_style report_style_t;
  typedef std::vector<unsigned int> diff_index_T;
  typedef std::list<std::pair<mpz_class, std::string> >::iterator sig_iter_T;

  typedef std::pair<unsigned int, std::string> time_unit_T;

  class SigRecord {
  public:
    SigRecord() {}
    SigRecord(const std::string&, const CRange&, unsigned int);
    std::string sig_name;
    CRange range;
    unsigned int width;
    std::list<std::pair<mpz_class, std::string> > value;
    std::list<std::pair<mpz_class, double> > rvalue;

    void record_change(mpz_class, const std::string&);
    void record_change(mpz_class, const double&);
    void record_change(mpz_class, const char&);

    //return index of differences between timestamps of a vector signal
    diff_index_T diffSig_onestep(sig_iter_T pos);

    void print_signal();
  };

  //waveform database definitions
  typedef std::map<std::string, SigRecord> wave_db_T;
  typedef std::map<std::string, SigRecord>::iterator wave_db_iter_T;  //database iterator


  class WaveDB {
  public:
    WaveDB();

    void set_delimiter(char);
    void set_time_unit(unsigned int, const std::string&);
    void push_scope(const std::string&);
    void pop_scope();
    void set_time(mpz_class);
    void add_id(const std::string&, const std::string&, const CRange&, unsigned int width);
    template<typename VT>
    void add_change(const std::string& id, const VT& v) {
      //assert(idDB.count(id));
      idDB[id].record_change(current_time, v);

      std::string sig = idDB[id].sig_name;
      
      std::list<std::string>::reverse_iterator lit = this->current_scope.rbegin();      
      sigDB[sig].record_change(current_time, v);
    }

    //geters
    char get_delimeter();
    std::string get_hier()
        { return this->hier; }

    time_unit_T get_time_unit()
        { return this->time_unit; }

    //return waveform info with signal ID as key
    wave_db_T& get_wave_db_id()
        { return this->idDB; }

    //return waveform info with signal name as key
    wave_db_T& get_wave_db_sig()
        { return this->sigDB; }

    //display functions
    void report_scope();
    void report_signals_all( report_style_t style );


  private:
    char delimiter;
    std::list<std::string> current_scope;
    std::string hier;
    std::pair<unsigned int, std::string> time_unit;
    mpz_class current_time;
    std::map<std::string, SigRecord> idDB;    // store the ids in VCD
    std::map<std::string, SigRecord> sigDB;   // store the signals in VCD

    std::map<std::string, std::string> sig_map; // Signal name::ID
  };

}

#endif
