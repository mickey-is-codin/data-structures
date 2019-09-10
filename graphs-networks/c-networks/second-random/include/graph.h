#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <stdbool.h>

int ** build_a_matrix(int max_nodes, bool zero_fill);
void fill_rand_graph(int ** a_matrix, int max_nodes);
void print_a_matrix(int ** a_matrix, int max_nodes);
float gen_link_prob(double mu, double sigma);

#endif
