#ifndef __GVIZ_STRUCTS_H__
#define __GVIZ_STRUCTS_H__

void gviz_tree(char * filename, TreeNode * root);
void gviz_traverse(FILE * dotfile, TreeNode * current_root, int * null_count);

#endif
