#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/tree.h"
#include "../include/gviz_structs.h"

void gviz_tree(char * filename, TreeNode * root) {

    FILE * dotfile = fopen(filename, "wb");

    fprintf(dotfile, "digraph BST {\n");
    fprintf(dotfile, "\tgraph [ dpi = 300 ];\n");
    fprintf(dotfile, "\tnode [shape=circle];\n");
    fprintf(dotfile, "\tsize=\"6,6\";\n");

    // Iterate through tree and build
    int null_count = 0;
    gviz_traverse(dotfile, root, &null_count);

    fprintf(dotfile, "}\n");
    fclose(dotfile);

}

void gviz_traverse(FILE * dotfile, TreeNode * current_root, int * null_count) {

    if (current_root == NULL) {
        return;
    }

    if (current_root->left != NULL) {
        fprintf(
            dotfile,
            "\t%d -> %d;\n",
            current_root->value, current_root->left->value
        );
    } else {
        (*null_count)++;
        fprintf(dotfile, "null%d [shape=point];\n", *null_count);
        fprintf(
            dotfile,
            "\t%d -> null%d;\n",
            current_root->value, *null_count
        );
    }

    if (current_root->right != NULL) {
        fprintf(
            dotfile,
            "\t%d -> %d;\n",
            current_root->value, current_root->right->value
        );
    } else {
        (*null_count)++;
        fprintf(dotfile, "null%d [shape=point]\n", *null_count);
        fprintf(
            dotfile,
            "\t%d -> null%d;\n",
            current_root->value, *null_count
        );
    }

    gviz_traverse(dotfile, current_root->left, null_count);
    gviz_traverse(dotfile, current_root->right, null_count);
}

