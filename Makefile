# Makefile Morse Code
CC = gcc
CFLAGS =  -O2 -Wall
LDFLAGS = -I.
OBJ = main.o libmorse.o init.o
DEPS = libmorse.h
EXEC = morse

all: main
#	@echo "Finish."
	@echo " "

main: $(OBJ)
#	@echo "Building the application core.."
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)
	rm -f $(OBJ)
#	@echo " "

%.o: %.c $(DEPS)
#	@echo "Building objects.."
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)
#	@echo " "

clean:
	@echo "Cleaning up.."
	rm -f $(EXEC)
	@echo " "