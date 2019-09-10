#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <stdbool.h>

#include "list.h"

int ** build_a_matrix(int max_nodes, bool zero_fill);
void fill_matrix_graph(int ** a_matrix, int max_nodes, int num_passes);
void print_a_matrix(int ** a_matrix, int max_nodes);

ListNode ** build_base_adj_list(int max_nodes);
void fill_list_graph(ListNode ** adj_list, int max_nodes);

float random_n_float(double mu, double sigma);
int randint(int lower, int upper);

#endif
