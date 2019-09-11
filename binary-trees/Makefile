RAND_EXEC=bin/rand-tree
ORD_EXEC=bin/ord-tree

SRC_C=src/tree.c
SRC_H=include/tree.h include/clog.h

RAND_C=src/rand_tree.c
ORD_C=src/ord_tree.c

CC=gcc

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=src/test_clog.c
COL_H=include/clog.h

all: rand order

rand: $(SRC_C) $(RAND_C)
	$(CC) $(SRC_C) $(RAND_C) -o $(RAND_EXEC)

order: $(SRC_C) $(ORD_C)
	$(CC) $(SRC_C) $(RAND_C) -o $(RAND_EXEC)

colors: $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC) $(CFLAGS)
