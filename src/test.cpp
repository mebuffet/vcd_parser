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
 * VCD parser test
 * 13/07/2013   Wei Song
 *
 *
 */

#include <iostream>
#include "vcd_parser.hpp"
#include "wave_db.hpp"

//:w
//using namespase std;

int main(int argc, char* argv[]) {
  vcd::VCDParser parser(argv[1]);
  
  vcd::WaveDB db;
  vcd::report_style_t d_style = vcd::STRING;
  
  parser.parse(&db);

  std::cout << "- delimeter field: '" << db.get_delimeter() << "'" << std::endl; 

  std::cout << "- hier field: '" << db.get_hier() << "'" << std::endl;

  vcd::time_unit_T time_unit = db.get_time_unit();
  std::cout << "- time unit: " << time_unit.first << " " << time_unit.second << std::endl;

  db.report_scope();
  db.report_signals_all (d_style);

  return 1;
  
}
