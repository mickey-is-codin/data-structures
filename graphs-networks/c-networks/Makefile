EXEC=bin/network
SRC_C=src/network.c src/graphs.c src/struct_print.c
SRC_H=include/graphs.h include/struct_print.h include/clog.h

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
