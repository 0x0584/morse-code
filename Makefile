# Makefile Morse Code
CC = gcc
#CFLAGS =  -ggdb -O2 -Wall -Wextra -pedantic -Wpadded 
CFLAGS = -ggdb -O2 -Wall -Wextra -pedantic -Wpadded 
LDFLAGS = -I.
OBJ = main.o libmorse.o init.o decode.o encode.o
DEPS = libmorse.h encode.h decode.h
EXEC = morse
#ARGS = 

all: main
	@echo "Finish."
#	@echo " "

main: $(OBJ)
#	@echo "Building the application core.."
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)
#	rm -f $(OBJ)
#	@echo " "

%.o: %.c $(DEPS)
#	@echo "Building objects.."
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS) 
#	@echo " "

run: clean all
	./$(EXEC) $(ARGS)
build:clean all
clean:
	@echo "Cleaning up.."
	rm -f $(EXEC)
	rm -f $(OBJ)
#	@echo " "

# end of Makefile
