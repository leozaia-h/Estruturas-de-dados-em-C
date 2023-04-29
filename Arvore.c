#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *left;
	struct node *right;
};

struct node* create_empty_tree() {
	return NULL;
}

struct node* crete_tree(struct node* left, struct node* right, int num) {
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->left = left;
	new_node->right = right;
	new_node->num = num;

	return new_node;
}

int is_empty(struct node* tree) {
	if(tree == NULL)
		return 1;
	else
		return 0;
}

struct node* add_to_tree(struct node* tree, int num) {
	if(tree == NULL) {
		tree = crete_tree(NULL, NULL, num);
	}
	else {
		if(num < tree->num)
			tree->left = add_to_tree(tree->left, num);
		else
			tree->right = add_to_tree(tree->right, num);
	}
	
	return tree;
}

void print_tree(struct node *tree) {
	if(!is_empty(tree)) {
		printf(" ( %d ", tree->num);
	
		if(tree->left == NULL)
			printf(" () ");
		else
			print_tree(tree->left);
		
		if(tree->right == NULL)
				printf(" () ");
		else
			print_tree(tree->right);
		
		printf(") ");
	}
}

int main(void) {
	int num;
	
	struct node* tree = create_empty_tree();
	
	for(int i = 0; i < 3; i++) {
		scanf("%d", &num);
		tree = add_to_tree(tree, num);
	}
	print_tree(tree);
	
	return 0;
}
