#ifndef __LIST_H__
#define __LIST_H__

typedef struct _ListNode {
    int value;
    char label[32];
    struct _ListNode * next;
} ListNode;

ListNode * create_node(int value);
ListNode * append(ListNode * head, int value);
void pop(ListNode * head);
void destroy_list(ListNode * head);
void print_list(ListNode * head);
int randint(int lower, int upper);

#endif
