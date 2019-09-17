#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "../include/a_list.h"
#include "../include/clog.h"
#include "../include/list.h"

ListNode * push_graph_node(ListNode * graph_head, int value) {

    if (graph_head == NULL) {
        return create_node(value);
    }

    ListNode * iter_node = graph_head;
    while (iter_node->next != NULL) {
        iter_node = iter_node->next;
    }
    iter_node->next = create_node(value);

    return graph_head;
}
