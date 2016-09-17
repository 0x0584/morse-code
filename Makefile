# Makefile Morse Code
CC = gcc
RM = rm -f
EXEC = morse

SRCDIR = src
OBJDIR = bin
DEPSDIR = include

SRC := $(shell find $(SRCDIR) -name '*.c')
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DEPS:= $(shell find $(DEPSDIR) -name '*.h')

CFLAGS = -ggdb -O2 -Wall -Wextra -pedantic -Wpadded 
LDFLAGS = -I.

ARGS = -f morse 

all: main
	@echo "Finish."
#	@echo " "

main: build-dir $(OBJ)
#	@echo "Building the application core.."
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)
#	rm -f $(OBJ)
#	@echo " "
build-dir:
	@$(call make-dir)

define make-dir
	for dir in $(OBJDIR); \
	do \
	mkdir -p $$dir; \
	done
endef

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
#	@echo "Building objects.."
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS) 
#	@echo " "

run: build
	@echo " "
	@echo "Execution starts, Passed arguments: " $(ARGS)
	@echo "-------"
	@echo " "
	./$(EXEC) $(ARGS)
build:clean all
clean:
	@echo "Cleaning up.."
	$(RM) $(EXEC)
	$(RM) $(OBJ)
#	@echo " "

# end of Makefile
