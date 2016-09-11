# include "libmorse.h"

/* _insert(r, s, ch) (recursive) 
 *
 * @PARAMETERS:
 *	r:	The root tree.
 *	s:	string contanes morse code.
 *	ch:	The characters value of the passed morse string.
 */
static void _insert(struct tree **r, const char *s, char ch);


/* insert(s, ch)
 *	 *I do not find something to describe this one with!*
 *
 * @PARAMETERS:
 *	s:	morse string.
 *	ch:     char value of morse string.
 */
static inline void insert(const char *s, char ch);

static inline void
insert(const char *s, char ch)
{
  if(*s == '.') _insert(&root->dit, ++s, ch);
  else if(*s == '-') _insert(&root->dah, ++s, ch);
}

static void
_insert(struct tree **r, const char *s, char ch)
{
  if(*r == NULL) *r = (struct tree *) calloc(1, sizeof(struct tree **));
  if(*s == '\0') (*r)->c = ch;
  else if(*s == '.') _insert(&(*r)->dit, ++s, ch);
  else if(*s == '-') _insert(&(*r)->dah, ++s, ch);
}

void
make(void)
{
  int i;
  
  root = (struct tree *) calloc(1, sizeof(*root));
  root->c = '/';
  
  for(i = 0; i < 26; ++i) insert(M[ALPHA][i], ('A' + i));
    
  for(i = 0; i < 10; ++i) insert(M[NUMERAL][i], ('0' + i));
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

char*
readf (const char *dir)
{
  char *buffer = NULL;
  FILE *handler;

  if ((handler = fopen(dir, "r"))) {
    int string_size, read_size;

    fseek(handler, 0, SEEK_END);
    string_size = ftell(handler);
    rewind(handler);

    buffer = (char*) malloc( sizeof(char) * (string_size + 1) );
        
    read_size = fread(buffer, sizeof(char), string_size, handler);
    buffer[string_size] = '\0';

    if (string_size != read_size) {
      free(buffer);
      buffer = NULL;
    }
    fclose(handler);
  }
  return buffer;
}

void 
fcoder(const char *path, void(*mode)(const char *))
{
  char *s;
  
  if((s = readf(path))) mode(s);
  else fputs("NO FILE WAS FOUND!",stderr);    
}
