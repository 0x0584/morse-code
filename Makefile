# Makefile Morse Code
CC = gcc
CFLAGS = -I.
OBJ = main.o libmorse.o
DEPS = libmorse.h
EXEC = morse
all: main
#	@echo "Finish."
	@echo " "
main: $(OBJ)
#	@echo "Building the application core.."
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)
	rm -f $(OBJ)
#	@echo " "

%.o: %.c $(DEPS)
#	@echo "Building objects.."
	$(CC) -c -o $@ $< $(CFLAGS)
#	@echo " "
clean:
	@echo "Cleaning up.."
	rm -f $(EXEC)
	@echo " "
