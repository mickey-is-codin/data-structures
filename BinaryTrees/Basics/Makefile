# EXECUTABLES
MAIN_EXE = bin/btree

# SOURCE FILES
SRC_C = build_tree.c tree.c
SRC_H = tree.h

# GCC
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
CFLAGS = -std=c99 -lpthread -g
DEBUG = -DDEBUG
CC = gcc

VALGRIND = valgrind --leak-check=full --track-origins=yes --tool=memcheck --verbose --log-file=
VALDEV = test.log

OBJS = *.o *.dSYM

$(MAIN_EXE): $(SRC_C)
	$(CC) -o $(MAIN_EXE) $(SRC_C) $(WARNING) $(ERROR) $(CFLAGS)

clean:
	rm -rf $(OBJS) $(MAIN_EXE) $(DOTFILE) $(DOT_OUTPUT) valgrind*.log *.b *.txt
