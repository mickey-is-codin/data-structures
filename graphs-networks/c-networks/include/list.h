#ifndef __LIST_H__
#define __LIST_H__

typedef struct _ListNode {
    int value;
    struct _ListNode * next;
} ListNode;

ListNode * create_node(int value);
void append(ListNode * head, int value);
void pop(ListNode * head);
void destroy_list(ListNode * head);
void print_list(ListNode * head);

#endif
