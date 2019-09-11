#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/tree.h"

TreeNode * create_treenode(int value) {

    TreeNode * new_node = malloc(sizeof(*new_node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

TreeNode * insert_treenode(TreeNode * current_root, int value) {

    // Base case
    if (current_root == NULL) {
        return create_treenode(value);
    }

    // Recur left
    if (value < current_root->value) {
        current_root->left = insert_treenode(current_root->left, value);
    }

    // Recur right
    if (value >= current_root->value) {
        current_root->right = insert_treenode(current_root->right, value);
    }

    return current_root;
}

void destroy_tree(TreeNode * current_root) {
    if (current_root == NULL) {
        return;
    }

    destroy_tree(current_root->left);
    destroy_tree(current_root->right);
    free(current_root);
}

int randint(int lower, int upper) {
    return ((rand() % (upper - lower + 1)) + lower);
}
