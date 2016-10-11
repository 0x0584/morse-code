/************************************************************************/
/*						       _		*/
/*						      | |     		*/
/*	 _ __ ___   ___  _ __ ___  ___    ___ ___   __| | ___ 		*/
/* 	| '_ ` _ \ / _ \| '__/ __|/ _ \  / __/ _ \ / _` |/ _ \		*/
/*	| | | | | | (_) | |  \__ \  __/ | (_| (_) | (_| |  __/ 		*/
/* 	|_| |_| |_|\___/|_|  |___/\___|  \___\___/ \__,_|\___|		*/
/*									*/
/* copyright (C) 2016  Anas Rchid  					*/
/* 									*/
/* This program is free software; you can redistribute it and/or	*/
/* modify it under the terms of the GNU General Public License		*/
/* as published by the Free Software Foundation; either version 2	*/
/* of the License, or (at your option) any later version.		*/
/* 									*/
/* This program is distributed in the hope that it will be useful,	*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of	*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	*/
/* GNU General Public License for more details.				*/
/* 									*/
/* You should have received a copy of the GNU General Public License	*/
/* along with this program; if not, write to the Free Software		*/
/* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,		*/
/* MA  02110-1301, USA.							*/
/*								        */
/* 	Last modification: 09/14/2016-15:29:10				*/
/*								        */
/************************************************************************/

# include "../include/libmorse.h"
# include "../include/decode.h"
# include "../include/encode.h"

/* <---------------------( Main )---------------------> */
int
main()
{
  /* Setup the tree */
  make();
  /* char s[STRING_SIZE]; */
  /* printf("\033[2J\033[;H"); */
  /* printf("\033[2J\033[0;0H"); */
  /* \033[0m | \x1b[2J\x1b[1;1H */
  /* printf("\033\143"); */
  /* fgets(s, sizeof(s), stdin); */
  puts("text.txt:");
  /* puts(decoder(encoder(s))); */
  puts(readf("text.txt"));
  getchar();
  puts("fencoder:");
  puts(fencoder("text.txt"));
  /* puts(decoder("... .. .. . . .. ... / - -- ")); */
  /* puts(fdecoder("morse.txt")); */
  /* getchar(); */
  /* printf("\033\143");   */

  /* Drop the tree */
  drop(); 

  return 0;
}
