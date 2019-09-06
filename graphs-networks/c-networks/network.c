#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "network.h"
#include "graphs.h"
#include "struct_print.h"
#include "clog.h"

int main(int argc, char ** argv) {

    printf("Beginning program...\n");

    int value = 10;

    log_red(value);
    // log_green("Testing Red with int: %d\n", x);
    // log_blue("Testing Red with int: %d\n", x);

    return EXIT_SUCCESS;
}
