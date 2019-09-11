#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/tree.h"
#include "../include/gviz_structs.h"

void gviz_tree(char * filename, TreeNode * root) {

    FILE * dotfile = fopen(filename, "wb");

    fprintf(dotfile, "graph unix {\n");
    fprintf(dotfile, "\tgraph [ dpi = 300 ];\n");
    fprintf(dotfile, "\tnode [shape=circle];\n");
    fprintf(dotfile, "\tsize=\"6,6\";\n");

    // Iterate through tree and build


    fprintf(dotfile, "}\n");
    fclose(dotfile);

}

