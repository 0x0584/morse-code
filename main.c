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
/* 	Last modification: 08/31/2016-20:11:29				*/
/************************************************************************/

/* <-----------------------------------( Abstraction )-----------------------------------> */
/* This program is about an old technique of transmitting text messages
 *  in a series of ON/OFF's called Morse code.
 *
 * Each Morse code symbol represents either a text character (letter or numeral)
 *  represented by a unique sequence of dots and dashes(dits and dahs).
 * 
 * This program can do the following:
 *	[ ] Convert 'text to morse' and 'morse to text' from 
 * 		both stdin or a text-file
 *	[ ] Write in morse code directly with the possibility to switch between
 *		morse code and text.  
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

# include <stdio.h>
# include <stdlib.h>

/* indexes of Morse-Array */
# define ALPHA 0
# define NUMERAL 1

/* <-----------------------( Data Structures )-----------------------> */
/* Morse code tree */
struct tree {
  char c;
  struct tree *dit;
  struct tree *dah;
} *root;


/* <-----------------------( Global Variables )---------------------> */
/* Morse code characters */
static const char *alpha[] = {
  ".-",   /* A */
  "-...", /* B */
  "-.-.", /* C */
  "-..",  /* D */
  ".",    /* E */
  "..-.", /* F */
  "--.",  /* G */
  "....", /* H */
  "..",   /* I */
  ".---", /* J */
  "-.-",  /* K */
  ".-..", /* L */
  "--",   /* M */
  "-.",   /* N */
  "---",  /* O */
  ".--.", /* P */
  "--.-", /* Q */
  ".-.",  /* R */
  "...",  /* S */
  "-",    /* T */
  "..-",  /* U */
  "...-", /* V */
  ".--",  /* W */
  "-..-", /* X */
  "-.--", /* Y */
  "--..", /* Z */
};
/* Morse code numerals */
static const char *numeral[] = {
  "-----", /* 0 */
  ".----", /* 1 */
  "..---", /* 2 */
  "...--", /* 3 */
  "....-", /* 4 */
  ".....", /* 5 */
  "-....", /* 6 */
  "--...", /* 7 */
  "---..", /* 8 */
  "----.", /* 9 */
};
/* Morse code array */
static const char **M[] = {alpha, numeral};

/* <---------------------( Function-Prototypes )---------------------> */
/* _insert(r, s, ch) (recursive) 
 *
 * @PARAMETERS:
 *	r:	The root tree.
 *	s:	string contanes morse code.
 *	ch:	The characters value of the passed morse string.
 */
static void _insert(struct tree **, const char *, char );

/* insert(s, ch)
 *	 *I do not find something to describe this one with!*
 *
 * @PARAMETERS:
 *	s:	morse string.
 *	ch:     char value of morse string.
 */
static inline void insert( const char *, char );

/* make()
 *      Fill Morse-tree.
 */
void make(void);

/* _drop(r)
 *	Frees the tree. 
 *
 * @PARAMETERS:
 *	r:	the root of the tree.
 */
void _drop(struct tree *);

/* drop()
 *	Call _drop() and pass root as argument to be freed.
 */
void drop(void);

/* encoder(s)
 *	Encode into morse code, convert text to morse code.
 *
 * @PARAMETERS:
 *	s:	string contains morse code.
 */
void encoder(const char *);

/* _decode(r, s)
 *	Follow the morse binary tree to decode the passed string.
 *
 * @PARAMETERS:
 *	r:	The Morse tree.
 *	s:	the string to decode.
 */
void _decoder(struct tree *, const char *);

/* decoder(s)
 *	Decode Morse code into text
 *
 * @PARAMETERS:
 *	s: string contains morse code
 */
void decoder(const char *);

/* <---------------------( Main )---------------------> */
int
main()
{
  return 0;
}
