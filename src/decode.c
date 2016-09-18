# include "../include/decode.h"

void
_decoder(struct tree *r,const char *s, char *ss)
{
  if(r == NULL) return;		/* there is no root to the tree */

  if(*s == '\0') *(ss++) = r->c;
  else if(*s == '/') *(ss++) = ' ';
  else if(*s == '\b' || *s == '\r') puts("test here");
  else if(*s == '\n') *(ss++) = '\n';
  else if(*s == '\t') *(ss++) = '\t';
  else if(*s == '.') _decoder(r->dit, ++s, ss);
  else if(*s == '-') _decoder(r->dah, ++s, ss);

}

char *
decoder(const char *ss)
{
  char *output = (char *) malloc(STRING_SIZE * sizeof(char)); /* Final message */
  char *o = (char *) malloc(sizeof(char)); /* Partial message */
  char *s = (char *) malloc(sizeof(*ss));
  strncpy(s, ss, strlen(ss) - 1);
  strcat(s, " ");

  
  while(*s) {
    char *str = (char *) strchr(s, ' ');
    o = (char *) realloc(o, sizeof(*str));
    
    if(str) {
      if((str - s) != 0) {
	char c[(str - s) + 1];
	memcpy(c, s, (str - s));
	c[(str - s)] = '\0';
	_decoder(root, c, o);
      }
      else {
	puts("str - s == 0");
      }
      s = str + 1;		/* Move to the next morse character */
    }
    else {
      _decoder(root, s, o);
      break;
    }
    strcat(output, o);		/* Concatenate the partial and final message */
    if(!*s) free(o);
  }
  /* free(s); */
  return output;
}

char *
fdecoder(const char *s)
{
  return fcoder(s, decoder);
}

