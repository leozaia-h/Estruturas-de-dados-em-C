#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int num;
    struct node *next;
    struct node *previous;
} node;

node* create_doubly_linekd_list() {
	printf("Lista criada.\n");
	
    return NULL;
}

node* add(node* head, int num) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->num = num;
    new_node->next = head;
    new_node->previous = NULL;

    if (head != NULL)
        head->previous = new_node;

	printf("O elemento %d foi adicionado na lista.\n", num);

    return new_node;
}

node* remove_node(node* head, int num) {
	node *current = head;
	while(current != NULL && current->num != num)
		current = current->next;
	
	if(current == NULL) {
		printf("O elemento %d não está na lista.\n", num);
		
		return head;
	}
	
	if(current == head) {
		head = current->next;
	}
	else {
		current->previous->next = current->next;
	}
	
	if(current->next != NULL) {
		current->next->previous = current->previous;
	}
	
	free(current);
	printf("O elemento %d foi removido da lista.\n", num);
	
	return head;
}

void print_list_head(node *head_ref) {
	node* tmp = head_ref;
    
	printf("NULL ");
	while(tmp != NULL) {
        printf("<- %d -> ", tmp->num);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void print_list_tail(node *head) {
    node* tail = head;

    while(tail->next != NULL) {
        tail = tail->next;
    }

	printf("NULL ");
    while(tail != NULL) {
        printf("<- %d -> ", tail->num);
        tail = tail->previous;
    }
    printf("NULL\n");
}

int main() {
    int x;
    node* list = create_doubly_linekd_list();

    while(scanf("%d", &x) != EOF) {
        list = add(list, x);
    }

	list = remove_node(list, 6);
	list = remove_node(list, 4);

    print_list_head(list);
    print_list_tail(list);

    return 0;
}
