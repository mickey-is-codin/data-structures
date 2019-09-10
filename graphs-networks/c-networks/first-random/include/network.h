#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "../include/list.h"

void parse_args(int argc, char ** argv, bool * generate_dot, int * max_nodes);
ListNode ** build_base_adj_list(int max_nodes);
void fill_graph(ListNode ** adj_list, int max_nodes);
int randn(double mu, double sigma);
int randint(int lower, int upper);

#endif
