EXEC=bin/bar-albert

SRC_C=src/main.c src/barabasi_albert.c src/a_list.c src/gviz_structs.c src/list.c
SRC_H=include/a_list.h include/gviz_structs.h include/clog.h include/list.h

CC=gcc
CFLAGS=-lm

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=src/test_clog.c
COL_H=include/clog.h

# GRAPH-BUILDING OPTIONS
SFDP_OPTS=sfdp -x -Goverlap=scale -Tpng

GVIZ_DOT=graphviz/list_graph.dot
GVIZ_IMG=graphviz/list_graph.png

PROG_FLAGS=-v -d $(GVIZ_LIST_DOT) -n 20

$(EXEC) : $(SRC_C) $(SRC_H)
	$(CC) $(SRC_C) -o $(EXEC)

colors: $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC) $(CFLAGS)

clean:
	@rm -rf $(EXEC)
