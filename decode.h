#ifndef DECODE_H
#define DECODE_H
#include "libmorse.h"

/* _decode(r, s)
 *	Follow the morse binary tree to decode the passed string.
 *
 * @PARAMETERS:
 *	r:	The Morse tree.
 *	s:	the string to decode.
 */
void _decoder(struct tree *, const char *, FILE *);

/* decoder(s)
 *	Decode Morse code into text
 *
 * @PARAMETERS:
 *	s: string contains morse code
 */
void decoder(const char *);

/* fdecoder(p)
 *	Call fcoder() passing decoder()
 *
 * @PARAMETERS:
 *	p:	Path to the text-file
 */
void fdecoder(const char *, FILE *);

void decodef(const char *s);

#endif	/* DECODE_H */
