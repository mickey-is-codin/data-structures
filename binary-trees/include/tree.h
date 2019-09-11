#ifndef __TREE_H__
#define __TREE_H__

/* TYPE DECLARATIONS */
typedef struct _TreeNode {
    int value;
    struct _TreeNode * left;
    struct _TreeNode * right;
} TreeNode;

TreeNode * create_treenode(int value);
TreeNode * insert_treenode(TreeNode * current_node, int value);
void destroy_tree(TreeNode * current_node);
int randint(int lower, int upper);

#endif
