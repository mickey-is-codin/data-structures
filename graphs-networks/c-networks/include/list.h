#ifndef __LIST_H__
#define __LIST_H__

typedef struct _ListNode {
    int value;
    char label[50];
    struct _ListNode * next;
} ListNode;

ListNode * create_node(int value);
void append(ListNode * head, int value);
void pop(ListNode * head);
void destroy_adj(ListNode * head, int num_nodes);
void print_list(ListNode * head);

#endif
