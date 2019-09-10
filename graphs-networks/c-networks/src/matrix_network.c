#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "../include/graph.h"
#include "../include/gviz_structs.h"
#include "../include/clog.h"

void parse_args(int argc, char ** argv, bool * generate_dot, int * max_nodes, int * num_passes);

int main(int argc, char ** argv) {

    printf("Beginning program...\n\n");

    // Seed random number generator using runtime
    srand(time(0));

    // Initialize values that will be set by command line args and then
    // parse the actual arguments using getopt(). Only check those arguments
    // if the user has invoked >=1 of them (argc conditional).
    bool generate_dot = false;
    int  max_nodes    = 10;
    int  num_passes   = 1;
    if (argc > 1) {
        parse_args(argc, argv, &generate_dot, &max_nodes, &num_passes);
    }

    // Initialze the adjacency matrix and fill it with zeros
    int ** a_matrix = build_a_matrix(max_nodes, true);

    //print_a_matrix(a_matrix, max_nodes);
    fill_a_matrix(a_matrix, max_nodes, num_passes);
    //print_a_matrix(a_matrix, max_nodes);

    if (generate_dot) {
        gviz_a_matrix("graphviz/matrix_graph.dot", a_matrix, max_nodes);
    }

    // Free adj matrix here

    return EXIT_SUCCESS;
}

void parse_args(int argc, char ** argv, bool * generate_dot, int * max_nodes, int * num_passes) {

    int opt;

    log_yell("==Command Line Arguments==\n");

    while ((opt = getopt(argc, argv, "dn:p:")) != -1) {
        switch (opt) {
            case 'd':
                *generate_dot = true;
                log_yell("graph .dot will be generated");
                break;
            case 'n':
                *max_nodes = atoi(optarg);
                log_yell("max nodes set to %d", *max_nodes);
                break;
            case 'p':
                *num_passes = atoi(optarg);
                log_yell("number of linking passes set to %d", *num_passes);
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
