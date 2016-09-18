# include "../include/encode.h"

char *
fencoder(const char *s)
{
  return fcoder(s, encoder);
}

char *
encoder(const char *s) /* Bug here: pass the array limit */
{
  char *output = (char *) malloc(STRING_SIZE * sizeof(char));
  *output = ' ';
  output = strchr(output, ' ');
  puts("Beginnig of encoder");
  /* puts(s); */
  for(;; ++s) {
    char ch = *s;

    if(ch == '\0') break;
    else if(isalpha(ch)) ch = toupper(ch), strcat(output, M[ALPHA][ch - 'A']);
    else if(isdigit(ch)) strcat(output, M[NUMERAL][ch - '0']);
    else if(ch == ' ') strcat(output, "/");
    else if(ch == '\n') {
      strcat(output, "\n");
      continue;
    }
    else if(ch == '\t') {
      strcat(output, "\t");
      continue;
    }
    strcat(output, " ");    
  }
  strcat(output, " ");    
  printf("the output:\n---------------\n%s\n--------------\n", output);
  return output;
}

