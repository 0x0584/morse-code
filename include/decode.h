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
void _decoder(struct tree *root, const char *input, char *output);

/* fdecoder(p)
 *	Call fcoder() passing decoder()
 *
 * @PARAMETERS:
 *	p:	Path to the text-file
 */
char *decoder(const char *string);

char *fdecoder(const char *path);

# endif	/* DECODE_H */
