#ifndef __LIST_H__
#define __LIST_H__

/* TYPE DEFINITIONS */
typedef struct _ListNode {
    int value;
    struct _ListNode * next;
} ListNode;

/* FUNCTION DECLARATIONS */
ListNode * append_listnode(ListNode * current_node, int value);
ListNode * create_listnode(int value);
void destroy_list(ListNode * current_node);

#endif
