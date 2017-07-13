#include "Queue.h"

Queue *doEmptyQueue(){
	Queue *address = (Queue*) calloc(1, sizeof(Queue));
	if(address == NULL){
		fprintf(stderr, "DO EMPTY QUEUE Function-> Error allocating the queue.\n");
		exit(0);
	}

	return address;
}

int adds(Queue *queue, ItemT item){
	if(queue == NULL){
		fprintf(stderr, "ADDS Function -> Invalid parameter.\n");
		return 0;
	}

	Cell *newCell = (Cell*) calloc(1, sizeof(Cell));
	if(newCell == NULL){
		fprintf(stderr, "ADDS Function -> Error allocating a new cell.\n");
		return 0;	
	}

	newCell->item = item;
	newCell->next = NULL;

	if(queue->length == 0){
		queue->first = queue->last = newCell;
	}
	else{
		queue->last->next = newCell;
		queue->last = newCell;
	}
	queue->length += 1;

	return 1;
}

int removes(Queue *queue){
	if(queue == NULL){
		fprintf(stderr, "REMOVES Function -> Invalid parameter.\n");
		return 0;
	}

	if(queue->length){
		if(queue->length == 1){
			queue->length--;
			free(queue->first);
			queue->first = queue->last = NULL;

			return 1;
		}
		Cell *aux = queue->first;
		queue->length--;
		queue->first = queue->first->next;
		free(aux);
			
		return 1;
	}

	return 0;
}

void destroy(Queue *queue){
	if(queue == NULL){
		fprintf(stderr, "DESTROY Function -> Invalid parameter.\n");
		return;
	}

	Cell *aux = queue->first;
	while(aux != NULL){
		queue->first = aux->next;
		free(aux);
		aux = queue->first;
	}
	free(queue);
}

void printQueue(Queue *queue){
	if(queue == NULL){
		fprintf(stderr, "PRINT QUEUE Function -> Invalid parameter.\n");
		return;
	}

	Cell *walker = queue->first;
	while(walker != NULL){
		printf("%d\n", walker->item);
		walker = walker->next;
	}
}
