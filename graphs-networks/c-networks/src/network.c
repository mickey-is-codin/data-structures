#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "../include/network.h"
#include "../include/graphs.h"
#include "../include/struct_print.h"
#include "../include/clog.h"

int main(int argc, char ** argv) {

    printf("Beginning program...\n");

    bool generate_dot = false;

    parse_args(argc, argv, &generate_dot);

    return EXIT_SUCCESS;
}

void parse_args(int argc, char ** argv, bool * generate_dot) {

    int opt;

    while ((opt = getopt(argc, argv, "dick")) != -1) {
        switch (opt) {
            case 'd':
                *generate_dot = true;
                log_yell("generate-dot specified");
                break;
            case 'f':
                printf("filename: %s\n", optarg);
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }

    for (; optind<argc; optind++) {
        printf("extra argument: %s\n", argv[optind]);
    }
}
