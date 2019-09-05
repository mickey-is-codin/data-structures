#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

TreeNode * insert_treenode(TreeNode * current_root, int value) {

    // Base case
    if (current_root == NULL) {
        printf("Inserting %d into tree\n", value);
        return create_treenode(value);
    }

    // Recur left
    if (value < current_root->value) {
        //printf("Recurring left\n");
        current_root->left = insert_treenode(current_root->left, value);
    }

    // Recur right
    if (value >= current_root->value) {
        //printf("Recurring right\n");
        current_root->right = insert_treenode(current_root->right, value);
    }

    return current_root;
}

TreeNode * create_treenode(int value) {

    TreeNode * new_node = malloc(sizeof(*new_node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void destroy_tree(TreeNode * current_root) {
    if (current_root == NULL) {
        return;
    }

    destroy_tree(current_root->left);
    destroy_tree(current_root->right);
    free(current_root);
}
