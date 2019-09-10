#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "../include/graph.h"

/* ADJACENCY MATRIX OPERATIONS */
int ** build_a_matrix(int num_nodes, bool zero_fill) {

    int ** a_matrix;
    a_matrix = malloc(sizeof(*a_matrix) * num_nodes);

    for (int init_ix=0; init_ix<num_nodes; init_ix++) {
        a_matrix[init_ix] = malloc(sizeof(*(a_matrix[init_ix])) * num_nodes);
    }

    if (zero_fill) {
        for (int row_ix=0; row_ix<num_nodes; row_ix++) {
            for (int col_ix=0; col_ix<num_nodes; col_ix++) {
                a_matrix[row_ix][col_ix] = 0;
            }
        }
    }

    return a_matrix;
}

void fill_a_matrix(int ** a_matrix, int num_nodes, int num_passes, int * total_connections) {

    int col_creep = 0;
    float link_prob;
    float prob_thresh = 0.5;
    float giant_comp_thresh = 1.0 / num_nodes;

    for (int pass_ix=0; pass_ix<num_passes; pass_ix++) {
        for (int row_ix=0; row_ix<num_nodes; row_ix++) {
            for (int col_ix=col_creep; col_ix<num_nodes; col_ix++) {
                link_prob = random_n_float(0.5, 0.1);

                if ((link_prob > prob_thresh) && (row_ix != col_ix)) {
                    a_matrix[row_ix][col_ix] += 1;
                    if (a_matrix[row_ix][col_ix] == 1) {
                        (*total_connections)++;
                    }
                }

            }
            col_creep++;
        }
        col_creep = 0;
    }

}

void print_a_matrix(int ** a_matrix, int num_nodes) {
    printf("\n==Adjacency Matrix==\n");
    for (int row_ix=0; row_ix<num_nodes; row_ix++) {
        for (int col_ix=0; col_ix<num_nodes; col_ix++) {
            printf("%d ", a_matrix[row_ix][col_ix]);
        }
        printf("\n");
    }
    printf("\n");
}

void destroy_a_matrix(int ** a_matrix, int num_nodes) {
    for (int mat_ix=0; mat_ix<num_nodes; mat_ix++) {
        free(a_matrix[mat_ix]);
    }
    free(a_matrix);
}

/* ADJACENCY LIST OPERATIONS */
ListNode ** build_a_list(int num_nodes) {
    ListNode ** a_list = malloc(sizeof(*a_list) * (num_nodes));

    for (int node_ix=0; node_ix<num_nodes; node_ix++) {
        a_list[node_ix] = create_node(node_ix);
    }

    return a_list;
}

void fill_a_list(ListNode ** a_list, int num_nodes) {

    int src_node;
    int dst_node;
    int full_graph_edges = (int) (num_nodes * (num_nodes - 1)) / 2;

    for (int rand_ix=0; rand_ix<full_graph_edges; rand_ix++) {

        do {
            src_node = randint(0, num_nodes-1);
            dst_node = randint(0, num_nodes-1);
        } while (dst_node == src_node);

        append(a_list[src_node], dst_node);
    }
}

void print_a_list(ListNode ** a_list, int num_nodes) {
    printf("\n==Adjacency List==\n");
    for (int list_ix=0; list_ix<num_nodes; list_ix++) {
        print_list(a_list[list_ix]);
        printf("\n");
    }
}

void destroy_a_list(ListNode ** a_list, int num_nodes) {
    for (int list_ix=0; list_ix<num_nodes; list_ix++) {
        destroy_list(a_list[list_ix]);
    }
    free(a_list);
}

/* STATS/GENERATION OPERATIONS */
int randint(int lower, int upper) {
    return ((rand() % (upper - lower + 1)) + lower);
}

float random_n_float(double mu, double sigma) {

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
