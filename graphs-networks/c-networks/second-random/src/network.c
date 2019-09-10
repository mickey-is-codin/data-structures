#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "../include/network.h"
#include "../include/graph.h"
#include "../include/gviz_structs.h"
#include "../include/clog.h"

int main(int argc, char ** argv) {

    printf("Beginning program...\n\n");

    // Seed random number generator using runtime
    srand(time(0));

    // Initialize values that will be set by command line args and then
    // parse the actual arguments using getopt()
    bool generate_dot = false;
    int max_nodes = 10;
    parse_args(argc, argv, &generate_dot, &max_nodes);

    int ** a_matrix = build_a_matrix(max_nodes);
    print_a_matrix(a_matrix, max_nodes);
    fill_graph(a_matrix, max_nodes);
    print_a_matrix(a_matrix, max_nodes);
    gviz_adj("graphviz/random_graph.dot", a_matrix, max_nodes);

    // Free adj matrix here

    return EXIT_SUCCESS;
}

void print_a_matrix(int ** a_matrix, int max_nodes) {
    printf("\n");
    for (int row_ix=0; row_ix<max_nodes; row_ix++) {
        for (int col_ix=0; col_ix<max_nodes; col_ix++) {
            printf("%d ", a_matrix[row_ix][col_ix]);
        }
        printf("\n");
    }
    printf("\n");
}

float normal_float(double mu, double sigma) {

    double u1, u2, w, mult;
    static double x1, x2;
    static bool call = false;

    if (call) {
        call = !call;
        return (mu + sigma * (double) x2);
    }

    do {
        u1 = -1 + ((double) rand() / RAND_MAX) * 2;
        u2 = -1 + ((double) rand() / RAND_MAX) * 2;
        w = pow(u1,2) + pow(u2,2);
    } while (w >= 1 || w == 0);

    mult = sqrt((-2 * log(w)) / w);
    x1 = u1 * mult;
    x2 = u2 * mult;

    call = !call;

    return (mu + sigma * (double) x1);
}

void fill_graph(int ** a_matrix, int max_nodes) {

    int total_connections = 0;
    int full_graph_edges = (int) (max_nodes * (max_nodes - 1) ) / 2;
    int col_creep = 0;
    float link_prob;
    float prob_thresh = 0.5;
    float giant_comp_thresh = 1.0 / max_nodes;
    int num_passes = 1;

    for (int pass_ix=0; pass_ix<num_passes; pass_ix++) {
        for (int row_ix=0; row_ix<max_nodes; row_ix++) {
            for (int col_ix=col_creep; col_ix<max_nodes; col_ix++) {
                link_prob = normal_float(0.5, 0.1);

                if ((link_prob > prob_thresh) && (row_ix != col_ix)) {
                    a_matrix[row_ix][col_ix] += 1;
                    total_connections++;
                }

            }
            col_creep++;
        }
        col_creep = 0;
    }

    float connected_ratio = (total_connections / (float) full_graph_edges) * 100.0;

    printf("Graph made a total of %d connections out of %d (%2.2f%% connected)\n",
        total_connections, full_graph_edges, connected_ratio);

}

int ** build_a_matrix(int max_nodes) {

    int ** a_matrix;
    a_matrix = malloc(sizeof(*a_matrix) * max_nodes);

    for (int init_ix=0; init_ix<max_nodes; init_ix++) {
        a_matrix[init_ix] = malloc(sizeof(*(a_matrix[init_ix])) * max_nodes);
    }

    for (int row_ix=0; row_ix<max_nodes; row_ix++) {
        for (int col_ix=0; col_ix<max_nodes; col_ix++) {
            a_matrix[row_ix][col_ix] = 0;
        }
    }

    return a_matrix;
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
