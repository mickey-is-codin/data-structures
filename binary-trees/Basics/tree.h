#ifndef __TREE_H__
#define __TREE_H__

/* TYPE DECLARATIONS */
typedef struct _TreeNode {
    int value;
    struct _TreeNode * left;
    struct _TreeNode * right;
} TreeNode;

/* FUNCTION DECLARATIONS */
TreeNode * insert_treenode(TreeNode * current_root, int value);
TreeNode * create_treenode(int value);
void destroy_tree(TreeNode * current_root);

#endif
