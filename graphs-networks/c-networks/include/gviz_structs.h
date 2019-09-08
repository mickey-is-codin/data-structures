#ifndef __GVIZ_STRUCTS_H__
#define __GVIZ_STRUCTS_H__

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void generate_gviz_list(ListNode * head, char * filename);
void gviz_adj(ListNode ** adj_list, int num_nodes);

#endif
