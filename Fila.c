#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
	int current_size;
	int head;
	int tail;
	int items[MAX_QUEUE_SIZE];
} queue;

int is_empty(queue *queue) {
	return queue->current_size;
}

queue* create_queue() {
	queue *new_queue = (queue*) malloc(sizeof(queue));
	new_queue->current_size = 0;
	new_queue->head = 0;
	new_queue->tail = MAX_QUEUE_SIZE-1;
	
	printf("Queue created.\n");
	
	return new_queue;
}

void enqueue(queue *queue, int item) {
	if(queue->current_size >= MAX_QUEUE_SIZE) {
		printf("Queue overflow.\n");
	}
	else {
		queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
		queue->items[queue->tail] = item;
		queue->current_size++;
		
		printf("%d enqueued.\n", item);
	}
}

int dequeue (queue *queue) {
	if(!is_empty(queue)) {
		printf("Queue underflow.\n");
		
		return -1;
	}
	else {
		int dequeued = queue->items[queue->head];
		queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
		queue->current_size--;
		
		printf("%d dequeued.\n", dequeued);
		
		return dequeued;
	}
}

int main() {
	
	queue *queue = create_queue();
	
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);

	return 0;
}
