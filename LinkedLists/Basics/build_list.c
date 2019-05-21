#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 32

void print_list(ListNode * print_node);

int main(int argc, char ** argv) {

    printf("Beginning linked list construction program...\n\n");

    ListNode * head = NULL;

    while (true) {

        printf("Enter command ('p' to print list, 'i' to insert value, 'x' to exit): ");
        char command = fgetc(stdin);
        if (command == '\n') {
            command = fgetc(stdin);
        }

        if (command == 'p') {
            printf("Printing current list\n");
            print_list(head);
        }

        if (command == 'i') {
            getchar();
            int insert_value = 0;
            char buffer[MAX];
            fgets(buffer, MAX, stdin);
            sscanf(buffer, "%d", &insert_value);
            head = append_listnode(head, insert_value);
        }

        if (command == 'x') {
            printf("Exiting...\n");
            destroy_list(head);
            break;
        }

    }

    return EXIT_SUCCESS;
}

void print_list(ListNode * print_node) {

    while (print_node != NULL) {
        printf("%d →", print_node->value);
        print_node = print_node->next;
    }
    printf("⏚\n");

}
