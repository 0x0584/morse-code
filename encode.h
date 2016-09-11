#ifndef ENCODE_H
#define ENCODE_H
#include "libmorse.h"

/* encoder(s)
 *	Encode into morse code, convert text to morse code.
 *
 * @PARAMETERS:
 *	s:	string contains morse code.
 */
void encoder(const char *);

/* fencoder(p)
 *	Call fcoder() passing encoder
 *
 * @PARAMETERS:
 *	p:	Path to text-file
 */
void fencoder(const char *, FILE *);

void encodef(const char *s);

#endif	/* ENCODE_H */
