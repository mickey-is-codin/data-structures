MAT_EXEC=bin/matrix-network
LIST_EXEC=bin/list-network

MAT_C=src/matrix_network.c
LIST_C=src/list_network.c

SRC_C=src/graph.c src/gviz_structs.c src/list.c
SRC_H=include/graph.h include/gviz_structs.h include/clog.h include/list.h

CC=gcc
CFLAGS=-lm

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=src/test_clog.c
COL_H=include/clog.h

# GRAPH-BUILDING OPTIONS
SFDP_OPTS=sfdp -x -Goverlap=scale -Tpng

GVIZ_LIST_DOT=graphviz/list_graph.dot
GVIZ_MAT_DOT=graphviz/matrix_graph.dot

GVIZ_LIST_IMG=graphviz/list_graph.png
GVIZ_MAT_IMG=graphviz/matrix_graph.png

all: list matrix

list: $(SRC_C) $(LIST_C)
	$(CC) $(SRC_C) $(LIST_C) -o $(LIST_EXEC) $(CFLAGS)

ldot: $(SRC_C) $(LIST_C)
	$(CC) $(SRC_C) $(LIST_C) -o $(LIST_EXEC) $(CFLAGS)
	$(LIST_EXEC) && dot -Tpng $(GVIZ_LIST_DOT) -o $(GVIZ_LIST_IMG)

lneat: $(SRC_C) $(LIST_C)
	$(CC) $(SRC_C) $(LIST_C) -o $(LIST_EXEC) $(CFLAGS)
	$(LIST_EXEC) && $(SFDP_OPTS) $(GVIZ_LIST_DOT) > $(GVIZ_LIST_IMG)

lcirc: $(SRC_C) $(LIST_C)
	$(CC) $(SRC_C) $(LIST_C) -o $(LIST_EXEC) $(CFLAGS)
	$(LIST_EXEC) && circo -Tpng $(GVIZ_LIST_DOT) -o $(GVIZ_LIST_IMG)

matrix: $(SRC_C) $(MAT_C)
	$(CC) $(SRC_C) $(MAT_C) -o $(MAT_EXEC) $(CFLAGS)

mdot: $(SRC_C) $(MAT_C)
	$(CC) $(SRC_C) $(MAT_C) -o $(MAT_EXEC) $(CFLAGS)
	$(MAT_EXEC) && dot -Tpng $(GVIZ_MAT_DOT) -o $(GVIZ_MAT_IMG)

mneat: $(SRC_C) $(MAT_C)
	$(CC) $(SRC_C) $(MAT_C) -o $(MAT_EXEC) $(CFLAGS)
	$(MAT_EXEC) && $(SFDP_OPTS) $(GVIZ_MAT_DOT) > $(GVIZ_MAT_IMG)

mcirc: $(SRC_C) $(MAT_C)
	$(CC) $(SRC_C) $(MAT_C) -o $(MAT_EXEC) $(CFLAGS)
	$(MAT_EXEC) && circo -Tpng $(GVIZ_MAT_DOT) -o $(GVIZ_MAT_IMG)

colors: $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC) $(CFLAGS)

clean:
	@rm -rf $(LIST_EXEC) $(MAT_EXEC)
