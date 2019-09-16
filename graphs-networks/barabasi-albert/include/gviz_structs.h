#ifndef __GVIZ_STRUCTS_H__
#define __GVIZ_STRUCTS_H__

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void gviz_a_matrix(char * filename, int ** a_matrix, int num_nodes);
void gviz_a_list(char * filename, ListNode ** adj_list, int num_nodes);

#endif
