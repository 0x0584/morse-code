# ifndef OTF_H
# define OTF_H
# include "../include/libmorse.h"
# include "../include/decode.h"
# include <unistd.h>
# include <sys/ioctl.h>	/* ioctl, TIOCGWINSZ */
# include <err.h>	/* err */
# include <fcntl.h>	/* open */
# include <getopt.h>
# include <termios.h>
# define BUFFER_SIZE 0x200 /* 512 */
# define EMPTY 0
# define FULL 1
# define USAGE "ESC to quit,\
 TAB to put a space,	    \
 RETURN to make a newline:"

char tmpinput;			/* user input */
extern char *buffer;

extern int /* wcol, wrow, */
  ch;
extern int buffer_state;	/* buffer_state: 0 EMPTY 1 FULL */

FILE* save;

/* Prototypes */
int getch( void );
void buffalloc();
void otf( void );


# endif	/* OTF_H */
