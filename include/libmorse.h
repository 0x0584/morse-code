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
# define STRING_SIZE 256

/* <-----------------------( Data Structures )-----------------------> */
/* Morse code tree */
# pragma pack(push)  /* push current alignment to stack */
# pragma pack(1)     /* set alignment to 1 byte boundary */

struct tree {
  char c;
  struct tree *dit;
  struct tree *dah;
} *root;

# pragma pack(pop) /* restore original alignment from stack */
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

/* fcoder(p, func)
 *	Decode from morse or Encode to morse, inputed
 *	 from Text file
 *
 * @PARAMETERS:
 *	p:	Path to text-file
 *	func:	Function as argument, (decoder, encoder) 
 */
char *fcoder(const char *, char *(*mode)(const char *));

/* readf(p)
 *	read a whole text file and returns it as (char *)
 *
 * @PARAMETERS:
 *	p:	Path to text-file
 */
char* readf(const char *);

# endif /* LIBMORSE_H */
