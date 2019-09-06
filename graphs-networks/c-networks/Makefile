EXEC=bin/network
SRC_C=network.c graphs.c struct_print.c
SRC_H=graphs.h struct_print.h clog.h

CC=gcc

# SPECIFIC TO CLOG
COL_EXEC=bin/test-clog
COL_C=test_clog.c
COL_H=clog.h

$(EXEC) : $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC)

$(COL_EXEC) : $(COL_C) $(COL_H)
	$(CC) $(COL_C) -o $(COL_EXEC)

clean:
	@rm -rf $(EXEC)
