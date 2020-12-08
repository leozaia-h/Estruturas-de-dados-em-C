#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    struct node *next;
} node;

node* add(node *head, int num) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->num = num;
    new_node->next = head;

    return new_node;
}

node* create_linked_list() {
    return NULL;
}

void print_linked_list(node *head) {
    while(head != NULL) {
        printf("%d ", head->num);
        head = head->next;
    }
        printf("\n");                                                                                                       }

int main() {
    int x;

    node* list = create_linked_list();

    while(scanf("%d", &x) != EOF) {
        list = add(list, x);
    }

    print_linked_list(list);

    return 0;
}
