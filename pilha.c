#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node{
    int item;
    struct node *next;
}node;

typedef struct stack{
    node *top;
}stack;


stack* create_stack() {
    stack *new_stack = (stack*) malloc(sizeof(stack));
    new_stack->top = NULL;
    printf("Stack criada\n");
    return new_stack;
}

void push (stack *stack, int item) {
    node *new_top = (node*) malloc(sizeof(node));
    new_top->item = item;
    new_top->next = stack->top;
    stack->top = new_top;
    printf("Push complete\n");
}

int pop (stack *stack) {
    if(is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    else {
        int num = stack->top->item;
        stack->top = stack->top->next;
        printf("Popped\n");
        return num;
    }
}

int is_empty(stack *stack) {
    if (stack->top == NULL)
        return 1;
    else
        return 0;
}

int main() {
    stack* stack = create_stack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));

    return 0;
}
