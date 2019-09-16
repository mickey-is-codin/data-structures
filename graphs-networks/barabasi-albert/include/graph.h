#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <stdbool.h>

#include "list.h"

int ** build_a_matrix(int max_nodes, bool zero_fill);
void fill_a_matrix(int ** a_matrix, int num_nodes, int num_passes, int * total_connections,
                   int link_chance);
void print_a_matrix(int ** a_matrix, int max_nodes);
void destroy_a_matrix(int ** a_matrix, int max_nodes);

ListNode ** build_a_list(int max_nodes);
void fill_a_list(ListNode ** a_list, int max_nodes);
void print_a_list(ListNode ** a_list, int max_nodes);
void destroy_a_list(ListNode ** a_list, int max_nodes);

bool check_for_link(int p);
float random_n_float(double mu, double sigma);
int randint(int lower, int upper);

#endif
