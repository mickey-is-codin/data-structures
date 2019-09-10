#include "../include/gviz_structs.h"
#include "../include/clog.h"

void gviz_a_matrix(char * filename, int ** a_matrix, int num_nodes) {

    log_green("Generating graphviz array of linked lists");

    FILE * dotfile = fopen(filename, "wb");

    fprintf(dotfile, "graph unix {\n");
    fprintf(dotfile, "\tgraph [ dpi = 300 ];\n");
    fprintf(dotfile, "\tnode [shape=circle];\n");
    fprintf(dotfile, "\tsize=\"6,6\";\n");
    fprintf(dotfile, "\trankdir=\"LR\";\n\n");

    for (int row_ix=0; row_ix<num_nodes; row_ix++) {
        for (int col_ix=0; col_ix<num_nodes; col_ix++) {
            if (a_matrix[row_ix][col_ix]) {
                for (int link_ix=0; link_ix<a_matrix[row_ix][col_ix]; link_ix++) {
                    fprintf(dotfile, "\t%d -- %d\n", row_ix, col_ix);
                }
            }
        }
    }

    fprintf(dotfile, "}\n");
    fclose(dotfile);
}

void gviz_a_list(char * filename, ListNode ** adj_list, int num_nodes) {

    log_green("Generating graphviz array of linked lists");

    FILE * dotfile = fopen(filename, "wb");

    fprintf(dotfile, "graph unix {\n");
    fprintf(dotfile, "\tgraph [ dpi = 300 ];\n");
    fprintf(dotfile, "\tnode [shape=circle];\n");
    fprintf(dotfile, "\tsize=\"6,6\";\n");
    fprintf(dotfile, "\trankdir=\"LR\";\n\n");

    for (int node_ix=0; node_ix<num_nodes; node_ix++) {

        ListNode * print_node = adj_list[node_ix];
        while (print_node->next != NULL) {
            fprintf(dotfile, "\t\"%s\" -- \"%s\"\n", adj_list[node_ix]->label, print_node->next->label);
            print_node = print_node->next;
        }

    }

    fprintf(dotfile, "}\n");
    fclose(dotfile);
}

