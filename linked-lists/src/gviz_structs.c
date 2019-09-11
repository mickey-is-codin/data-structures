#include "../include/gviz_structs.h"
#include "../include/clog.h"

void gviz_list(char * filename, ListNode * head) {

    FILE * dotfile = fopen(filename, "wb");

    fprintf(dotfile, "graph unix {\n");
    fprintf(dotfile, "\tgraph [ dpi = 300 ];\n");
    fprintf(dotfile, "\tnode [shape=circle];\n");
    fprintf(dotfile, "\tsize=\"6,6\";\n");
    fprintf(dotfile, "\trankdir=\"LR\";\n\n");

    ListNode * print_node = head;
    while (print_node->next != NULL) {
        fprintf(dotfile, "\t\"%s\" -- \"%s\"\n", print_node->label, print_node->next->label);
        print_node = print_node->next;
    }

    fprintf(dotfile, "}\n");
    fclose(dotfile);
}

