#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#include "../include/barabasi_albert.h"
#include "../include/clog.h"
#include "../include/a_list.h"
#include "../include/list.h"
#include "../include/gviz_structs.h"

int parse_args(int argc, char ** argv, bool * verbose, bool * generate_dot,
                char ** dot_filename, int * max_nodes, int * steps);

int main(int argc, char ** argv) {

    printf("Beginning program...\n\n");

    srand(time(0));

    bool verbose = false;
    bool generate_dot = false;
    char * dot_filename = "graphviz/matrix_graph.dot";
    int  max_nodes = 10;
    int steps = 10;
    if (argc > 1) {
        int arg_result = parse_args(
            argc, argv,
            &verbose,
            &generate_dot,
            &dot_filename,
            &max_nodes,
            &steps
        );
        if (arg_result == -1) {
            return EXIT_SUCCESS;
        }
    }

    ListNode * graph_head = NULL;
    for (int i=0; i<10; i++) {
        graph_head = push_graph_node(graph_head, i);
    }

    print_list(graph_head);

    destroy_list(graph_head);

    return EXIT_SUCCESS;
}

int parse_args(int argc, char ** argv, bool * verbose, bool * generate_dot,
                char ** dot_filename, int * max_nodes, int * steps) {

    int opt;

    log_yell("==Command Line Arguments==\n");

    while ((opt = getopt(argc, argv, "vd:n:s:")) != -1) {
        switch (opt) {
            case 'v':
                *verbose = true;
                log_yell("verbose output on");
                break;
            case 'd':
                *generate_dot = true;
                *dot_filename = optarg;
                log_yell("graph .dot will be generated");
                break;
            case 'n':
                *max_nodes = atoi(optarg);
                log_yell("max nodes set to %d", *max_nodes);
                break;
            case 's':
                *steps = atoi(optarg);
                log_yell("number of steps set to %d", *steps);
                break;
            case ':':
                printf("option needs a value\n");
                return -1;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }

    for (; optind<argc; optind++) {
        printf("extra argument: %s\n", argv[optind]);
    }

    printf("\n");
    return 1;
}
