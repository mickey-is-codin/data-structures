#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

ListNode * append_listnode(ListNode * current_node, int value) {

    if (current_node == NULL) {
        current_node = create_listnode(value);
        return current_node;
    }

    ListNode * head = current_node;

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    ListNode * new_node = create_listnode(value);
    current_node->next = new_node;

    return head;
}

ListNode * create_listnode(int value) {

    ListNode * new_node = malloc(sizeof(*new_node));
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

void destroy_list(ListNode * current_node) {

    while (current_node->next != NULL) {
        ListNode * victim = current_node;
        current_node = current_node->next;
        free(victim);
    }
    free(current_node);

    printf("Tree has been successfully and completely destroyed...\n");
}
