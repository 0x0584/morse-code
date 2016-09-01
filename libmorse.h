# ifndef LIBMORSE_H
# define LIBMORSE_H
# include <stdio.h>		/* fputc(), fputs() */
# include <stdlib.h>		/* calloc() */
# include <string.h>		/* memcpy() */
# include <ctype.h>		/* isalpha(), isdigit(), toupper()*/

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


# endif /* LIBMORSE_H */
