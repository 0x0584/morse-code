# include "../include/otf.h"

char *buffer = NULL;
int buffer_state, ch;

int
getch( void )
{
  int ch;
  struct termios oldt, newt;
                 
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO ); /* remove ICANON AND ECHO */
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

  return ch;
}

void
initotf( void )
{
  buffer = NULL;
  buffer_state = EMPTY;
}

void
buffalloc()
{
  if(buffer == NULL)
    buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
  else if((sizeof(buffer) + 10) >= BUFFER_SIZE) 
    buffer = realloc(buffer, sizeof(buffer + BUFFER_SIZE));
}

void
otf( void )
{
  int showvalid = 0;
  char NAME[10];
  /* int length = strlen(USAGE); 	/\* or: for(;usage[length++]!='\0';); *\/ */

  initotf();
  /* If the buffer was not empty */
  buffalloc();  
  if( buffer[0] != (char)0 ) {
    buffer_state = FULL;	/* change the buffer's state */

    printf("[\x1B[31mBACK UP\x1B[0m]:\n");
    printf("%s ", buffer);
    puts("\nWANT TO RELOAD IT? (Y/n)");

    tmpinput = getch();
    if( tmpinput == 'n' || tmpinput == 'N' ){
      memset(buffer, 0x00, strlen(buffer));      /* Clean the buffer */
      buffer_state = EMPTY;
      system("clear");
    }
  } else buffalloc();
  
  /* if( !buffer_state ) { */
  /*   for (int j = 0; j < wcol; j+=1) */
  /*     printf("="); */
  /*   for (int i = 0; i < ((wcol - length)/2 + (wcol%2)); i++) */
  /*     printf(" "); */
  /* } */

  /* if( !buffer_state ) { */
  /*   puts(USAGE); */
  /*   for(int j = 0; j < wcol; j+=1) printf("=");  */
  /* } */

  
  while( feof(stdin) != EOF ) {	/* If the user press Ctrl-d */
    buffalloc();
    
    switch ((ch = toupper(getch()))) {
    case 127:			/* ASCII 127: DEL */
      if (showvalid == 0) {
	showvalid = 1;
	puts("test");
      } 
      else {
	puts("test2");
	showvalid = 0;
      }
      break;
      
    case 60:			/* ASCII 60: '<' */
      system("clear");
      puts(decoder(buffer));
      /* puts("here"); */
      printf("\nBACK? PRESS ENTER\n");
      getch();
      system("clear");
      
      for(int i = 0;buffer[i]!='\0'; ++i)
	if (buffer[i] == '/') {
	  putchar(32);		/* ASCII 32: SPACE */
	  continue;
	}
	else printf("%c", buffer[i]);
      break;
      
    case 9: /*ASCII 9: '\t' */ 
      fputc('\t', stdout);
      strcat(buffer, " / ");
      // printf("hi\033[;H");
      break;
      
    case 10: /* ASCII 10: '\n' */
      strcat(buffer, "\n");
      fputc('\n', stdout);
      break;
      
    case 27: /* ASCII 27: ESC */
      putchar('\n');
      if (!(*buffer == 0x00)) { 
	printf("WANT TO SAVE THE FILE? (Y/n)");
	//puts("WANT TO SAVE THE FILE? (Y/n)");
	//scanf("%c", &temp);
	tmpinput = getch();
	if ( tmpinput == 'Y' || tmpinput == 'y') {
	  printf("NAME IT (e.i. morse.txt)\t");
	  scanf("%9s", NAME);
	  puts(NAME);
	  getchar();
	  save = fopen(NAME,"w");
	  if (save  == NULL) fputs("ERROR WHILE SAVING \
					 			TEH FILE(THERE\'S STILL A BACKUP!)",stderr);		 
	  else {
	    //puts("here");
	    puts(buffer);
	    fprintf(save,"%s \n",buffer);
	    buffer = (char*) NULL;
	  }
	  fclose(save);
	}
      }
      return;
      
    default: break;
    }
    
    /* mchiz = 0; */
    if (isalpha(ch)) {	
      strcat(buffer, M[ALPHA][(ch - 'A')]);
      printf("%s ", M[ALPHA][(ch - 'A')]);
      //for(;AN[ALPHA][(ch - 'A')][mchiz++] != '\0';);
      //printf("\n%d\n", mchiz);
      strcat(buffer, " ");
    } else if (isdigit(ch)) {
      strcat(buffer, M[NUMERAL][(ch - '0')]);
      printf("%s ", M[NUMERAL][(ch - '0')]);
      //for(;AN[NUMERIC][(ch - '0')][mchiz++] != '\0';);
      //printf("\n%d\n", mchiz);
      strcat(buffer, " ");
    }
    // printf("\n%d\n", sizeof(buffer));
  }
  
}
