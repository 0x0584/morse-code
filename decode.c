# include "decode.h"

/* ... */


void
_decoder(struct tree *r,const char *s, FILE *f)
{
  if(r == NULL) return;
  if(*s == '\0') fputc(r->c, stdout);
  else if(*s == '/') fputc(' ', stdout);
  else if(*s == '\n') fputc('\n', stdout);
  else if(*s == '\t') fputc('\t', stdout);
  else if(*s == '.') _decoder(r->dit, ++s, f);
  else if(*s == '-') _decoder(r->dah, ++s, f);
}

void
fdecoder(const char *s, FILE *f)
{
  char *str;
  
  while(*s) {
    str = (char *) strchr(s, ' ');
    if(str) {
      if((str - s) != 0) {
	char c[(str - s) + 1];
	memcpy(c, s, (str - s));
	c[(str - s)] = '\0';
	_decoder(root, c, f);
      }
      s = str + 1;
    }
    else {
      _decoder(root, s, f);
      break;
    }
  }
  fputc('\n', f);
}

void
decoder(const char *s)
{
  fdecoder(s, stdout);
}

void decodef(const char *s)
{
  fcoder(s, decoder);
}

