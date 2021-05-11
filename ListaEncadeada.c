#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int num;
    struct node *next;
} node;

node* create_linked_list() {
	printf("Lista criada.\n");
	
    return NULL;
}

node* add(node *head, int num) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->num = num;
    new_node->next = head;
	
	printf("O elemento %d foi adicionado na lista.\n", num);
	
    return new_node;
}

node* remove_node(node *head, int num) {
    node *prev = NULL;
	node *current = head;
	
	while(current != NULL && current->num != num) {
		prev = current;
		current = current->next;
	}
	if(current == NULL) {
		printf("O elemento %d não está na lista.\n", num);
		
		return head;
	}
	if(prev == NULL)
		head = current->next;
	else
		prev ->next = current->next;
	
	free(current);
	printf("O elemento %d foi removido da lista.\n", num);
	
	return head;
}

void print_linked_list(node *head) {
    while(head != NULL) {
        printf("%d -> ", head->num);
        head = head->next;
    }
        printf("NULL\n");                                                                                                       
}	

int main() {
    int x;

    node* list = create_linked_list();

    while(scanf("%d", &x) != EOF) {
        list = add(list, x);
    }
	
	list = remove_node(list, 6);
	list = remove_node(list, 4);

    print_linked_list(list);

    return 0;
}
