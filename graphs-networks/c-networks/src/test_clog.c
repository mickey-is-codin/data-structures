#include <stdio.h>
#include <stdlib.h>

#include "../include/clog.h"

int main(int argc, char ** argv) {

    log_red("Red");
    log_bred("Bold Red");
    log_green("Green");
    log_bgreen("Bold Green");
    log_yell("Yellow");
    log_byell("Bold Yellow");
    log_blue("Blue");
    log_bblue("Bold Blue");
    log_mag("Magenta");
    log_bmag("Bold Magenta");
    log_cyan("Cyan");
    log_bcyan("Bold Cyan");

    int random_integerino = 5;
    log_int(random_integerino);

    return EXIT_SUCCESS;
}
