#ifndef __NETWORK_H__
#define __NETWORK_H__

void parse_args(
    int argc,
    char ** argv,
    bool * generate_dots,
    int * max_nodes
);
int randn(double mu, double sigma);

#endif
