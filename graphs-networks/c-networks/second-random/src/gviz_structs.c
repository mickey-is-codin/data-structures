#include "../include/gviz_structs.h"
#include "../include/clog.h"

void gviz_adj(char * filename, int ** a_matrix, int num_nodes) {

    log_green("Generating graphviz array of linked lists");

    FILE * dotfile = fopen(filename, "wb");

    fprintf(dotfile, "graph unix {\n");
    fprintf(dotfile, "\tgraph [ dpi = 300 ];\n");
    fprintf(dotfile, "\tnode [shape=circle];\n");
    fprintf(dotfile, "\tsize=\"6,6\";\n");
    fprintf(dotfile, "\trankdir=\"LR\";\n\n");



    fprintf(dotfile, "}\n");
    fclose(dotfile);
}
