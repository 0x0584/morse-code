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
/* 	Last modification: 09/04/2016-04:23:42				*/
/************************************************************************/

/* <-----------------------------------( Abstraction )-----------------------------------> */
/* This program is about an old technique of transmitting text messages
 *  in a series of ON/OFF's called Morse code.
 *
 * Each Morse code symbol represents either a text character (letter or numeral)
 *  represented by a unique sequence of dots and dashes(dits and dahs).
 * 
 * This program can do the following:
 *	# Convert 'text to morse' and 'morse to text' from:
 * 		[X]	 stdin
 *		[ ]	 text-file
 *	# Write in morse code:
 *		[ ]	 directly 
 *		[ ]	 with the possibility to switch between morse code and text.  
 *
 * We can use Dichotomic-Search, it is a search algorithm that operates by selecting
 *	between two distinct alternatives (dichotomies) at each step. A good example
 *	is Binary-Search.
 *
 * This figure below is a dichotomic table of the Morse code.
 *	 Shifting to the left represents a Dah(-), to the right represente a Dit(.)
 *
 *			   _____(Dah)______START______(Dit)_______			  
 *			  |					  |                       
 *		 _________T_________	                 _________E________         
 *		|                   |                   |	      	   |                  
 *	    ____M____	        ____N____           ____A____	       ____I____        
 *  	   |         |         |         |         |         |	      |         |         
 *      ___O___   ___G___   ___K___   ___D___   ___W___	     R	   ___U___   ___S___     
 *     |       | |       | |       | |       | |       |     |	  |       | |	    |    
 *   __-__     . Q       Z Y	   C X	     B J       P     L    _       F V	  __H__  
 *  |     |    |	 |		     | |		  |	    |    |     | 
 *  0     9    8	 7		     6 1		  2	    3    4     5 
 */

# include "libmorse.h"
# include "decode.h"
# include "encode.h" 
/* <---------------------( Main )---------------------> */
int
main()
{
  /* Setup the tree */
  make();


  /* printf("\033[2J\033[;H"); */
  /* printf("\033[2J\033[0;0H"); */
  /* \033[0m | \x1b[2J\x1b[1;1H */
  printf("\033\143");
  puts("-----encoder-test-----\n");
  encoder("youssef achker");
  getchar();

  printf("\033\143");
  puts("-----decoder-test-----\n");
  decoder(".... . .-.. .-.. --- / .-- --- .-. .-.. -..");
  getchar();

  printf("\033\143");
  puts("-----fdecoder-test-----\n");
  puts(readf("morse.txt"));
  decodef("morse.txt");
  
  getchar();
  /* puts(""); */
  printf("\033\143");
  puts("-----fencoder-test-----\n");
  puts(readf("text.txt"));
  encodef("text.txt");
  printf("\033\143");  



  /* Drop the tree */
  drop(); 

  return 0;
}
