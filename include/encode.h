# ifndef ENCODE_H
# define ENCODE_H
# include "../include/libmorse.h"

/* encoder(s)
 *	Encode into morse code, convert text to morse code.
 *
 * @PARAMETERS:
 *	s:	string contains morse code.
 */
char *encoder(const char *string);

/* fencoder(p)
 *	Call fcoder() passing encoder
 *
 * @PARAMETERS:
 *	p:	Path to text-file
 */
char *fencoder(const char *path);

# endif	/* ENCODE_H */
