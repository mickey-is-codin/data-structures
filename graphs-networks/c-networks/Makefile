EXEC=bin/network
SRC_C=src/network.c src/graph.c src/gviz_structs.c src/list.c
SRC_H=include/graph.h include/gviz_structs.h include/clog.h include/list.h

CC=gcc

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=src/test_clog.c
COL_H=include/clog.h

$(EXEC) : $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC)

colors: $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC)

clean:
	@rm -rf $(EXEC)
