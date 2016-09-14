# ifndef DECODE_H
# define DECODE_H
# include "../include/libmorse.h"
# define STRING_SIZE 256

/* _decode(r, s)
 *	Follow the morse binary tree to decode the passed string.
 *
 * @PARAMETERS:
 *	r:	The Morse tree.
 *	s:	the string to decode.
 */
void _decoder(struct tree *, const char *, char *);

/* fdecoder(p)
 *	Call fcoder() passing decoder()
 *
 * @PARAMETERS:
 *	p:	Path to the text-file
 */
char *decoder(const char *);

char *fdecoder(const char *s);

# endif	/* DECODE_H */
