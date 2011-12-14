/***************************************************************************
 *   Copyright (C) 2007 by AC   *
 *   agcarat@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>
#include <pcap.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
  int option;
  char  * infile = NULL, * outfile = NULL;
  uint32_t clientisn;
  uint32_t serverisn;
  while (-1 != (option = getopt(argc,argv, "i:o:rc:s:")))
  {
	  switch (option)
	  {
		  case 'r':
			  break;
		  case 'i':
			  infile = optarg;
			  break;
		  case 'o':
			  outfile = optarg;
			  break;
		  case 's':
			  serverisn = atoi(optarg);
		  	  break;
		  case 'c':
			  clientisn = atoi(optarg);
			  break;

	  }		 
  }
  if (infile ==NULL) {
	cout << "ERROR, you must provided a -i arg" << endl;
	return EXIT_FAILURE;  
  }
  if (outfile ==NULL) {
	  cout << "ERROR, you must provided a -o arg" << endl;
	  return EXIT_FAILURE;  
  }
  return EXIT_SUCCESS;
}
