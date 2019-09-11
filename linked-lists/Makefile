# EXECUTABLES
EXEC = bin/list

# SOURCE FILES
SRC_C = src/build_list.c src/list.c src/gviz_structs.c
SRC_H = include/list.h include/gviz_structs.h

CC = gcc

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=src/test_clog.c
COL_H=include/clog.h

# GRAPH-BUILDING OPTIONS
SFDP_OPTS=sfdp -x -Goverlap=scale -Tpng

GVIZ_DOT=graphviz/list.dot
GVIZ_IMG=graphviz/list.png

$(EXEC): $(SRC_C)
	$(CC) -o $(MAIN_EXE) $(SRC_C) $(WARNING) $(ERROR) $(CFLAGS)

ldot: $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC)
	$(EXEC) && dot -Tpng $(GVIZ_DOT) -o $(GVIZ_IMG)

lneat: $(SRC_C) $(LIST_C)
	$(CC) $(SRC_C) $(LIST_C) -o $(EXEC) $(CFLAGS)
	$(EXEC) && $(SFDP_OPTS) $(GVIZ_DOT) > $(GVIZ_IMG)

lcirc: $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC) $(CFLAGS)
	$(EXEC) && circo -Tpng $(GVIZ_DOT) -o $(GVIZ_IMG)

colors: $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC) $(CFLAGS)
