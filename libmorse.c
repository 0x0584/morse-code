# include "libmorse.h"

void
make(void)
{
  int i;
  
  root = (struct tree *) calloc(1, sizeof(*root));
  root->c = '/';
  
  for(i = 0; i < 26; ++i) insert(M[ALPHA][i], ('A' + i));
    
  for(i = 0; i < 10; ++i) insert(M[NUMERAL][i], ('0' + i));
}

static void
_insert(struct tree **r, const char *s, char ch)
{
  if(*r == NULL) *r = (struct tree *) calloc(1, sizeof(struct tree **));
  if(*s == '\0') (*r)->c = ch;
  else if(*s == '.') _insert(&(*r)->dit, ++s, ch);
  else if(*s == '-') _insert(&(*r)->dah, ++s, ch);
}

static inline void
insert(const char *s, char ch)
{
  if(*s == '.') _insert(&root->dit, ++s, ch);
  else if(*s == '-') _insert(&root->dah, ++s, ch);
}

void
_drop(struct tree *r)
{
  if(r){
    _drop(r->dit);
    _drop(r->dah);
    free(r);
  }
}

void
drop(void)
{
  _drop(root);
}

void
_decoder(struct tree *r,const char *s)
{
  if(r == NULL) return;
  if(*s == '\0') fputc(r->c, stdout);
  else if(*s == '/') fputc(' ', stdout);
  else if(*s == '.') _decoder(r->dit, ++s);
  else if(*s == '-') _decoder(r->dah, ++s);
}

void
decoder(const char *s)
{
  char *str;
  
  while(*s){
    str = (char *) strchr(s, ' ');
    if(str){
      if((str - s) != 0){
	char c[(str - s) + 1];
	memcpy(c, s, (str - s));
	c[(str - s)] = '\0';
	_decoder(root, c);
      }
      s = str + 1;
    }
    else {
      _decoder(root, s);
      break;
    }
  }
  fputc('\n', stdout);
}

void
encoder(const char *s)
{
  for(;; ++s){
    char ch = *s;
    if(ch == '\0') break;
    else if(isalpha(ch)) ch = toupper(ch), fputs(M[ALPHA][ch - 'A'], stdout);
    else if(isdigit(ch)) fputs(M[NUMERAL][ch - '0'], stdout);
    else if(ch == ' ') fputc('/', stdout);
    fputc(' ', stdout);
  }
  fputc('\n', stdout);
}

