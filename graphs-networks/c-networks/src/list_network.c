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

void parse_args(int argc, char ** argv, bool * generate_dot, int * max_nodes);

int main(int argc, char ** argv) {

    printf("Beginning program...\n\n");
    srand(time(0));

    // Values set from command line arguments.
    bool generate_dot = false;
    int max_nodes = 10;

    parse_args(argc, argv, &generate_dot, &max_nodes);

    ListNode ** adj_list = build_a_list(max_nodes);
    fill_a_list(adj_list, max_nodes);

    if (generate_dot) {
        gviz_a_list("graphviz/list_graph.dot", adj_list, max_nodes);
    }

    //destroy_adj(*adj_list, max_nodes);

    return EXIT_SUCCESS;
}

void parse_args(int argc, char ** argv, bool * generate_dot, int * max_nodes) {

    int opt;

    while ((opt = getopt(argc, argv, "dn:")) != -1) {
        switch (opt) {
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
