#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "../include/graph.h"
#include "../include/gviz_structs.h"
#include "../include/clog.h"

void parse_args(int argc, char ** argv, bool * verbose, bool * generate_dot, int * num_nodes, int * num_passes);

int main(int argc, char ** argv) {

    printf("Beginning program...\n\n");

    srand(time(0));

    bool verbose = false;
    bool generate_dot = false;
    int  num_nodes    = 10;
    int  num_passes   = 1;
    if (argc > 1) {
        parse_args(argc, argv, &verbose, &generate_dot, &num_nodes, &num_passes);
    }

    printf("Building initial adjacency matrix...");
    int ** a_matrix = build_a_matrix(num_nodes, true);
    log_green("✓");

    int total_connections = 0;
    int full_graph_edges = (int) (num_nodes * (num_nodes - 1) ) / 2;

    fill_a_matrix(a_matrix, num_nodes, num_passes, &total_connections);

    float connected_ratio = (total_connections / (float) full_graph_edges) * 100.0;

    if (generate_dot) {
        printf("Generating graphviz dotfile...");
        gviz_a_matrix("graphviz/matrix_graph.dot", a_matrix, num_nodes);
        log_green("✓");
    }

    if (verbose) {
        print_a_matrix(a_matrix, num_nodes);
        printf("Graph made a total of %d connections out of %d (%2.2f%% connected)\n",
               total_connections, full_graph_edges, connected_ratio);
    }

    printf("Destroying adjacency matrix...");
    destroy_a_matrix(a_matrix, num_nodes);
    log_green("✓");

    log_green("\nAll Done!\n");
    return EXIT_SUCCESS;
}

void parse_args(int argc, char ** argv, bool * verbose, bool * generate_dot,
                int * num_nodes, int * num_passes) {

    int opt;

    log_yell("==Command Line Arguments==\n");

    while ((opt = getopt(argc, argv, "vdn:p:")) != -1) {
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
                *num_nodes = atoi(optarg);
                log_yell("max nodes set to %d", *num_nodes);
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

    printf("\n");
}
