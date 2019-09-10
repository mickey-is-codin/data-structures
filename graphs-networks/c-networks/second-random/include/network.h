#ifndef __NETWORK_H__
#define __NETWORK_H__

void parse_args(int argc, char ** argv, bool * generate_dot, int * max_nodes);
int ** build_a_matrix(int max_nodes);
void fill_graph(int ** a_matrix, int max_nodes);
float normal_float(double mu, double sigma);
void print_a_matrix(int ** a_matrix, int max_nodes);

#endif
