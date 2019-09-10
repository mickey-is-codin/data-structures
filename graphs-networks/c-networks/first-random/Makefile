EXEC=bin/network
SRC_C=src/network.c src/graph.c src/gviz_structs.c src/list.c
SRC_H=include/graph.h include/gviz_structs.h include/clog.h include/list.h

CC=gcc
CFLAGS=-lm

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=src/test_clog.c
COL_H=include/clog.h

SFDP_OPTS=sfdp -x -Goverlap=scale -Tpng
GVIZ_DIR=graphviz/
GVIZ_LIST_DOT=graphviz/list_graph.dot
GVIZ_LIST_IMG=graphviz/list_graph.png

$(EXEC) : $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC) $(CFLAGS)

colors: $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC) $(CFLAGS)

dotgraph: $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC) $(CFLAGS)
	$(EXEC) && dot -Tpng $(GVIZ_LIST_DOT) -o $(GVIZ_LIST_IMG)
	open $(GVIZ_LIST_IMG)

neatgraph: $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC) $(CFLAGS)
	$(EXEC) && $(SFDP_OPTS) $(GVIZ_LIST_DOT) > $(GVIZ_LIST_IMG)
	open $(GVIZ_LIST_IMG)

circlegraph: $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC) $(CFLAGS)
	$(EXEC) && circo -Tpng $(GVIZ_LIST_DOT) -o $(GVIZ_LIST_IMG)
	open $(GVIZ_LIST_IMG)

clean:
	@rm -rf $(EXEC)
