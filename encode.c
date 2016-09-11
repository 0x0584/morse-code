# include "encode.h"

void
encodef(const char *s)
{
  fcoder(s, encoder);
}

void
encoder(const char *s)
{
  fencoder(s,stdout);
}

void
fencoder(const char *s, FILE *f)
{
  for(;; ++s) {
    char ch = *s;
    if(ch == '\0') break;
    else if(isalpha(ch)) ch = toupper(ch), fputs(M[ALPHA][ch - 'A'], f);
    else if(isdigit(ch)) fputs(M[NUMERAL][ch - '0'], f);
    else if(ch == ' ') fputc('/', f);
    else if(ch == '\n') {
      fputc('\n', f);
      continue;
    }
    else if(ch == '\t') {
      fputc('\t', f);
      continue;
    }
    fputc(' ', f);
  }
  fputc('\n', f);
}

