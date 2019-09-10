#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "../include/list.h"
#include "../include/graph.h"
#include "../include/gviz_structs.h"
#include "../include/clog.h"

void parse_args(int argc, char ** argv, bool * verbose, bool * generate_dot, int * max_nodes);

int main(int argc, char ** argv) {

    printf("Beginning program...\n\n");
    srand(time(0));

    bool verbose = false;
    bool generate_dot = false;
    int max_nodes = 10;

    parse_args(argc, argv, &verbose, &generate_dot, &max_nodes);

    ListNode ** a_list = build_a_list(max_nodes);
    fill_a_list(a_list, max_nodes);

    if (generate_dot) {
        gviz_a_list("graphviz/list_graph.dot", a_list, max_nodes);
    }

    if (verbose) {
        print_a_list(a_list, max_nodes);
    }

    destroy_a_list(a_list, max_nodes);

    return EXIT_SUCCESS;
}

void parse_args(int argc, char ** argv, bool * verbose, bool * generate_dot, int * max_nodes) {

    int opt;

    while ((opt = getopt(argc, argv, "vdn:")) != -1) {
        switch (opt) {
            case 'v':
                *verbose = true;
                log_yell("verbose output on");
                break;
            case 'd':
                *generate_dot = true;
                log_yell("graph .dot will be generated");
                break;
            case 'n':
                *max_nodes = atoi(optarg);
                log_yell("max nodes set to %d", *max_nodes);
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
