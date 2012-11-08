.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(CFLAGS) $<

CC = @gcc

# Normal CFLAGS
#CFLAGS = -g -Wall -O2

# Strict CFLAGS
#CFLAGS = -Wall -ansi -pedantic

# Paranoid CFLAGS
CFLAGS = -W -Wall -ansi -pedantic -Wbad-function-cast -Wcast-align -Wcast-qual -Wchar-subscripts -Winline \
	 -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes \
	 -Wwrite-strings
SRC = list.c 
OBJ = list.o

SCFLAGS1 = -W -Wall -ansi -pedantic -Wbad-function-cast -Wcast-align -Wcast-qual
SCFLAGS2 = -Wchar-subscripts -Winline -Wmissing-prototypes -Wnested-externs
SCFLAGS3 = -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes -Wwrite-strings
JCFLAGS = $(SCFLAGS1)\n\t\t$(SCFLAGS2)\n\t\t$(SCFLAGS3)

C = \033[1;33m[CC]\033[0;0m 
O = \033[1;32m[OK]\033[0;0m
R = \033[1;31m[RM]\033[0;0m
I = \033[1;34m[IN]\033[0;0m

all: $(OBJ)

	@echo "$(I) => Compiler:"
		@echo "\tGNU C Compiler\n"

	@echo "$(I) => Flags:"
		@echo "\tParanoid Flags"
		@echo "\t-W\t\t\t Warnings "
		@echo "\t-Wall\t\t\t All warnings are enabled"
		@echo "\t-ansi\t\t\t Should follow ANSI C"
		@echo "\t-pedantic\t\t Issue all the mandatory diagnostics listed in the C standard"
		@echo "\t-Wbad-function-cast\t Warn whenever a function call is cast to a non-matching type"
		@echo "\t-Wcast-align\t\t Warn whenever a pointer is a cast such that the required alignment of the target is increased"
		@echo "\t-Wcast-qual\t\t Warn whenever a pointer is a cast such that the required alignment of the target is increased"
		@echo "\t-Wchar-subscripts\t Warn if an array subscript has tipe char"
		@echo "\t-Winline\t\t Warn if a function can not be inlined"
		@echo "\t-Wmissing-prototypes\t Warn if a global function is defined without a previous prototype declaration"
		@echo "\t-Wnested-externs\t Warn if an extern declaration is encountered within a function"
		@echo "\t-Wpointer-arith\t\t Warn about anything that depends on the size of a function type or of void"
		@echo "\t-Wredundant-decls\t Warn if anything is declared more than once in the same scope"
		@echo "\t-Wshadow\t\t Warn whenever a local variable shadows another local variable"
		@echo "\t-Wsctrict-prototypes\t Warn if a function is declared or defined without specifying the argument types"
		@echo "\t-Wwrite-strings\t\t Warning to find compile times code that can try to write into a string constant\n"

	@echo "$(I) => Objects:"
		@echo "\tlist.o\t\t Simple linked list object\n"

	$(CC) $(CFLAGS) $(OBJ) -o main

	@echo "$(I) => Usage: "
	@echo "\tTo compile: make"
	@echo "\tTo clean: make clean"
	@echo "\tTo execute: ./main\n"

	@echo "$(O) Source compiled!"
clean:
	@echo "Removing all objects..."
	$(RM) $(OBJ) main
	@echo "$(R) Removed all object files and main binary file"
list.o: list.c
	@echo "Compiling list.c..."
	@echo "$(C) $(CC) \t-c list.c $(JCFLAGS)"
	$(CC) $(CFLAGS) -c list.c
	@echo "$(O) Linked list ready.\n"
