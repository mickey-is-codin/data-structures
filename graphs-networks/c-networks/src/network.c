#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/network.h"
#include "../include/graphs.h"
#include "../include/struct_print.h"
#include "../include/clog.h"

int main(int argc, char ** argv) {

    printf("Beginning program...\n");

    int opt;

    while ((opt = getopt(argc, argv, ":if:lrx")) != -1) {
        switch (opt) {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
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

    return EXIT_SUCCESS;
}
