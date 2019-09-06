EXEC=bin/network
SRC_C=network.c graphs.c struct_print.c
SRC_H=graphs.h struct_print.h clog.h

CC=gcc

$(EXEC) : $(SRC_H) $(SRC_C)
	$(CC) $(SRC_C) -o $(EXEC)

clean:
	@rm -rf $(EXEC)
