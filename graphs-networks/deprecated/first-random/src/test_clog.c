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

    int random_int = 5;
    long random_long = 1000001;
    double random_double = 2.0;
    float random_float = 4.2;

    log_int(random_int);
    log_long(random_long);
    log_double(random_double);
    log_float(random_float);

    return EXIT_SUCCESS;
}
