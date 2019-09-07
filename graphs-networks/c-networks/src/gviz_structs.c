#include "../include/gviz_structs.h"
#include "../include/clog.h"

void generate_gviz_list(ListNode * head, char * filename) {

    log_green("Generating graphviz linked list");

    FILE * dotfile = fopen(filename, "wb");

    fprintf(dotfile, "digraph unix {\n");
    fprintf(dotfile, "\tsize=\"6,6\";\n");
    fprintf(dotfile, "\trankdir=\"LR\";\n\n");

    ListNode * print_node = head;
    while (print_node->next != NULL) {
        fprintf(dotfile, "\t%d -> %d\n", print_node->value, print_node->next->value);
        print_node = print_node->next;
    }

    fprintf(dotfile, "}\n");
    fclose(dotfile);

}
