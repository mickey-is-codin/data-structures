#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "../include/network.h"
#include "../include/list.h"
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

    // This program utilizes an adjacency list rather than an adjacency
    // matrix. The adjacency list takes the form of an array of
    // linked lists. Size of the array is max_nodes, while each
    // linked list size grows with the program.
    ListNode ** adj_list = build_base_adj_list(max_nodes);
    fill_graph(adj_list, max_nodes);
    gviz_adj("graphviz/list_graph.dot", adj_list, max_nodes);

    // Destroy adjacency list here.

    return EXIT_SUCCESS;
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

void fill_graph(ListNode ** adj_list, int max_nodes) {

    // Iterate through each possible connection on the
    // graph. If a random pick is above 0.5, then
    // create a connection between those two nodes.

    int full_graph_nodes = (int) (max_nodes * (max_nodes - 1)) / 2;
    float link_prob;
    int connection_ix = 0;
    for (int src_ix=0; src_ix<max_nodes; src_ix++) {
        for (int dst_ix=0; dst_ix<max_nodes; dst_ix++) {

            connection_ix++;
            if (connection_ix == full_graph_nodes) {
                return;
            }

            link_prob = normal_float(0.5, 0.05);

            printf("Probability of link between %d and %d: %.2f\n", src_ix, dst_ix, link_prob);
            if (link_prob > 0.5) {
                append(adj_list[src_ix], dst_ix);
            }
        }
    }
}

ListNode ** build_base_adj_list(int max_nodes) {

    ListNode ** adj_list = malloc(sizeof(*adj_list) * (max_nodes));

    for (int node_ix=0; node_ix<max_nodes; node_ix++) {
        adj_list[node_ix] = create_node(node_ix);
    }

    return adj_list;
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
