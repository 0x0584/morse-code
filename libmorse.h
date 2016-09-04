# ifndef LIBMORSE_H
# define LIBMORSE_H
# include <stdio.h>		/* fputc(), fputs() */
# include <stdlib.h>		/* calloc() */
# include <string.h>		/* memcpy() */
# include <ctype.h>		/* isalpha(), isdigit(), toupper()*/

/* indexes of Morse-Array */
# define ALPHA 0
# define NUMERAL 1
# define LINE_SIZE 128
/* <-----------------------( Data Structures )-----------------------> */
/* Morse code tree */
struct tree {
  char c;
  struct tree *dit;
  struct tree *dah;
} *root;

/* <-----------------------( Global Variables )---------------------> */

extern const char /* Morse code characters */ *alpha[],
  /* Morse code numerals */ *numeral[],
  /* Morse code array */ **M[];

/* <---------------------( Function-Prototypes )---------------------> */

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

/* fcoder(p, func)
 *	Decode from morse or Encode to morse, inputed
 *	 from Text file
 *
 * @PARAMETERS:
 *	p:	Path to text-file
 *	func:	Function as argument, (decoder, encoder) 
 */
void fcoder(const char *, void(*mode)(const char *));

/* readf(p)
 *	read a whole text file and returns it as (char *)
 *
 * @PARAMETERS:
 *	p:	Path to text-file
 */
char* readf(const char *);

/* fdecoder(p)
 *	Call fcoder() passing decoder()
 *
 * @PARAMETERS:
 *	p:	Path to the text-file
 */
void fdecoder(const char *);

/* fencoder(p)
 *	Call fcoder() passing encoder
 *
 * @PARAMETERS:
 *	p:	Path to text-file
 */
void fencoder(const char *);

# endif /* LIBMORSE_H */
