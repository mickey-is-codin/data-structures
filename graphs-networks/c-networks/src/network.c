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
    srand(time(0));

    // Values set from command line arguments.
    bool generate_dot = false;
    int max_nodes = 5;

    parse_args(argc, argv, &generate_dot, &max_nodes);

    int time_gap = randn(50, 15);
    log_int(time_gap);

    int connection_node;

    ListNode ** adj_list = malloc(sizeof(*adj_list) * (max_nodes));

    for (int node_ix=0; node_ix<max_nodes; node_ix++) {
        adj_list[node_ix] = create_node(node_ix);
    }

    int src_node;
    int dst_node;
    int full_graph_edges = (int) (max_nodes * (max_nodes - 1)) / 2;
    for (int rand_ix=0; rand_ix<full_graph_edges; rand_ix++) {

        do {
            src_node = randint(0, max_nodes-1);
            dst_node = randint(0, max_nodes-1);
        } while (dst_node == src_node);

        printf("Connection %d: %d to %d\n", rand_ix, src_node, dst_node);

        append(adj_list[src_node], dst_node);
    }

    gviz_adj("graphviz/list_graph.dot", adj_list, max_nodes);

    //destroy_adj(*adj_list, max_nodes);

    return EXIT_SUCCESS;
}

int randint(int lower, int upper) {
    return ((rand() % (upper - lower + 1)) + lower);
}

int randn(double mu, double sigma) {

    double u1, u2, w, mult;
    static double x1, x2;
    static bool call = false;

    if (call) {
        call = !call;
        return (int) (mu + sigma * (double) x2);
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

    return (int) (mu + sigma * (double) x1);
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
