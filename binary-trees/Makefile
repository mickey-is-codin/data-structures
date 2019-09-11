RAND_EXEC=bin/rand-tree
ORD_EXEC=bin/ord-tree

SRC_C=src/tree.c src/gviz_structs.c
SRC_H=include/tree.h include/gviz_structs.h include/clog.h

RAND_C=src/rand_tree.c
ORD_C=src/ord_tree.c

CC=gcc

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=src/test_clog.c
COL_H=include/clog.h

# GRAPH-BUILDING OPTIONS
SFDP_OPTS=sfdp -x -Goverlap=scale -Tpng

GVIZ_RAND_DOT=graphviz/rand_tree.dot
GVIZ_ORD_DOT=graphviz/ord_tree.dot

GVIZ_RAND_IMG=graphviz/rand_tree.png
GVIZ_ORD_IMG=graphviz/ord_tree.png

RAND_FLAGS=-v -d $(GVIZ_RAND_DOT) -n 20
ORD_FLAGS=-v -d $(GVIZ_ORD_DOT) -n 20 -p 1

all: rand order

rand: $(SRC_C) $(RAND_C)
	$(CC) $(SRC_C) $(RAND_C) -o $(RAND_EXEC)

rdot: $(SRC_C) $(RAND_C)
	$(CC) $(SRC_C) $(RAND_C) -o $(RAND_EXEC)
	$(RAND_EXEC) && dot -Tpng $(GVIZ_RAND_DOT) -o $(GVIZ_RAND_IMG)

order: $(SRC_C) $(ORD_C)
	$(CC) $(SRC_C) $(ORD_C) -o $(ORD_EXEC)

odot: $(SRC_C) $(ORD_C)
	$(CC) $(SRC_C) $(ORD_C) -o $(ORD_EXEC)
	$(ORD_EXEC) && dot -Tpng $(GVIZ_ORD_DOT) -o $(GVIZ_ORD_IMG)

colors: $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC) $(CFLAGS)
