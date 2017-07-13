#include "Stack.h"

Stack *doEmptyStack(){
	Stack *address = (Stack*) calloc(1, sizeof(Stack));
	if(address == NULL){
		fprintf(stderr, "DO EMPTY STACK Function-> Error allocating the stack.\n");
		exit(0);
	}

	return address;
}

int adds(Stack *stack, ItemT item){
	if(stack == NULL){
		fprintf(stderr, "ADDS Function -> Invalid parameter.\n");
		return 0;
	}

	Cell *newCell = (Cell*) calloc(1, sizeof(Cell));
	if(newCell == NULL){
		fprintf(stderr, "ADDS Function -> Error allocating a new cell.\n");
		return 0;	
	}

	newCell->item = item;
	newCell->below = stack->last;

	if(stack->length == 0){
		stack->first = stack->last = newCell;
	}
	else{
		stack->last = newCell;
	}
	stack->length += 1;

	return 1;
}

int removes(Stack *stack){
	if(stack == NULL){
		fprintf(stderr, "REMOVES Function -> Invalid parameter.\n");
		return 0;
	}

	if(stack->length){
		if(stack->length == 1){
			stack->length--;
			free(stack->last);
			stack->first = stack->last = NULL;

			return 1;
		}
		Cell *aux = stack->last;
		stack->length--;
		stack->last = stack->last->below;
		free(aux);
			
		return 1;
	}

	return 0;
}

void destroy(Stack *stack){
	if(stack == NULL){
		fprintf(stderr, "DESTROY Function -> Invalid parameter.\n");
		return;
	}

	Cell *aux = stack->last;
	while(aux != NULL){
		stack->last = aux->below;
		free(aux);
		aux = stack->last;
	}
	free(stack);
}

void printStack(Stack *stack){
	if(stack == NULL){
		fprintf(stderr, "PRINT STACK Function -> Invalid parameter.\n");
		return;
	}

	Cell *walker = stack->last;
	while(walker != NULL){
		printf("%d\n", walker->item);
		walker = walker->below;
	}
}
