#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    struct node *next;
    struct node *previous;
}node;

node* create_doubly_linekd_list() {
    return NULL;
}

node* add(node* head, int num) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->num = num;
    new_node->next = head;
    new_node->previous = NULL;

    if (head != NULL)
        head->previous = new_node;

    return new_node;
}
void print_list_head(node *head_ref) {                                                                                      node* tmp = head_ref;
    while(tmp != NULL) {
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
}

void print_list_tail(node *head) {
    node* tail = head;

    while(tail->next != NULL) {
        tail = tail->next;
    }

    while(tail != NULL) {
        printf("%d ", tail->num);
        tail = tail->previous;
    }
    printf("\n");
}

int main() {
    int x;
    node* list = create_doubly_linekd_list();

    while(scanf("%d", &x) != EOF) {
        list = add(list, x);
    }

    print_list_head(list);
    print_list_tail(list);

    return 0;
}
