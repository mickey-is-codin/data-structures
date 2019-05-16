#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 32

void print_tree(TreeNode * root, int space);

int main(int argc, char ** argv) {

    printf("Beginning tree construction program...\n\n");

    TreeNode * root = NULL;

    while (true) {

        printf("Enter command ('p' to print tree or 'i' to insert value): ");
        char command = fgetc(stdin);
        if (command == '\n') {
            command = fgetc(stdin);
        }

        if (command == 'p') {
            printf("Printing current tree\n");
            print_tree(root, 10);
        }

        if (command == 'i') {
            getchar();
            int insert_value = 10;
            char buffer[MAX];
            fgets(buffer, MAX, stdin);
            sscanf(buffer, "%d", &insert_value);
            root = insert_treenode(root, insert_value);
        }

    }

    destroy_tree(root);

    return EXIT_SUCCESS;
}

void print_tree(TreeNode * root, int space) {

    int count = 10;

    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += count;

    // Process right child first
    print_tree(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = count; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->value);

    // Process left child
    print_tree(root->left, space);
}
