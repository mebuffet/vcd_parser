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

#include "wave_db.hpp"

using std::string;

using namespace std;

vcd::SigRecord::SigRecord(const std::string& sig_name, const CRange& range, unsigned int width)
  : sig_name(sig_name), range(range), width(width) {}

void vcd::SigRecord::record_change(mpz_class ctime, const std::string& val) {
  if(value.empty() || value.back().second != val)
    value.push_back(std::pair<mpz_class, string>(ctime, val));
}

void vcd::SigRecord::record_change(mpz_class ctime, const char& val) {
  stringstream ss;
  std::string sval;

  ss << val;
  ss >> sval;

  if(value.empty() || value.back().second != sval)
    value.push_back(std::pair<mpz_class, string>(ctime, sval));
}

void vcd::SigRecord::record_change(mpz_class ctime, const double& val) {
  if(rvalue.empty() || rvalue.back().second != val)
    rvalue.push_back(std::pair<mpz_class, double>(ctime, val));
}

void vcd::SigRecord::print_signal()
{

    cout << "Signal name: " << sig_name << endl;
    cout << "Changes:";
    
    if (value.size() != 0)
    {
        std::list<std::pair<mpz_class, std::string> >::iterator sig_iter;
        cout << value.size() << "\n" << endl;
        for (sig_iter = this->value.begin(); sig_iter != this->value.end(); ++sig_iter)
        {
            mpz_class tmp_mpz = sig_iter->first;
            string tmp_nam = sig_iter->second;
            cout << "-> " << tmp_mpz.get_d() << "\t:\t" << tmp_nam << endl;
        }
    }
    else
    {
        std::list<std::pair<mpz_class, double> >::iterator sig_iter;
        cout << rvalue.size() << "\n" << endl;
        for (sig_iter = this->rvalue.begin(); sig_iter != this->rvalue.end(); ++sig_iter)
        {
            mpz_class tmp_mpz = sig_iter->first;
            double tmp_num = sig_iter->second;
            cout << "-> " << tmp_mpz.get_d() << "\t:\t" << tmp_num << endl;
        }
    }  
    cout << endl;
}

vcd::WaveDB::WaveDB() 
  : delimiter('/'), time_unit(1, "ns"), current_time(0) { }

void vcd::WaveDB::set_delimiter(char d) {
  delimiter = d;
}

void vcd::WaveDB::set_time_unit(unsigned int v, const string& u) {
  time_unit.first = v;
  time_unit.second = u;
}

void vcd::WaveDB::push_scope(const string& s) {
  if(current_scope.size() == 0)
    hier = s;
  else
    hier += "/" + s;
  current_scope.push_back(s);
}

void vcd::WaveDB::pop_scope() {
  if(current_scope.size() <= 1)  
    hier = "";
  else
    hier = hier.substr(0, hier.size() - current_scope.back().size() - 1);
  current_scope.pop_back();
}

void vcd::WaveDB::set_time(mpz_class t) {
  current_time = t;
}

void vcd::WaveDB::add_id(const std::string& id, const std::string& ref, const CRange& r, unsigned int w) {
  idDB[id] = SigRecord(ref, r, w);
  sigDB[ref] =  SigRecord(ref, r, w);

  sig_map[id] = ref;
}


char vcd::WaveDB::get_delimeter()
{
    return this->delimiter;
}

void vcd::WaveDB::report_scope()
{
    std::list<std::string>::iterator lit;

    cout << "--Scope Report--\n" << endl;

    for(lit = current_scope.begin(); lit != current_scope.end(); ++lit)
    {
       string cur = *lit;
       cout << cur << endl;
    }
}

void vcd::WaveDB::report_signals_all( vcd::report_style_t style )
{
   //report all signal changes
   //iterates the idDB map
   
    std::map<std::string, vcd::SigRecord>::iterator sig_iter;

    cout << "--Signal Report--\n" << endl; 
    cout << "Total Signals:" << sigDB.size() << "\n" << endl;

   for (sig_iter = sigDB.begin(); sig_iter != sigDB.end(); ++sig_iter)
   {
       string tmp_nam = sig_iter->first;
       vcd::SigRecord tmp_sig = sig_iter->second;

       cout << "Signal ID: " << tmp_nam << endl;
       tmp_sig.print_signal();

   }

}

