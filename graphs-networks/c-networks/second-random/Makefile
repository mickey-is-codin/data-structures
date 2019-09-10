EXEC=bin/network
SRC_C=src/network.c src/graph.c src/gviz_structs.c src/list.c
SRC_H=include/graph.h include/gviz_structs.h include/clog.h include/list.h

CC=gcc
CFLAGS=-lm

SFDP_OPTS=sfdp -x -Goverlap=scale -Tpng
GVIZ_DIR=graphviz/
GVIZ_LIST_DOT=graphviz/random_graph.dot
GVIZ_LIST_IMG=graphviz/random_graph.png

$(EXEC) : $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC) $(CFLAGS)

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
