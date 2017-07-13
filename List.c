#include "List.h"

List *doEmptyList(){
	List *address = (List*) calloc(1, sizeof(List));
	if(address == NULL){
		fprintf(stderr, "DO EMPTY LIST Function-> Error allocating the list.\n");
		exit(0);
	}

	return address;
}

int adds(List *list, ItemT item){
	if(list == NULL){
		fprintf(stderr, "ADDS Function -> Invalid parameter.\n");
		return 0;
	}

	Cell *newCell = (Cell*) calloc(1, sizeof(Cell));
	if(newCell == NULL){
		fprintf(stderr, "ADDS Function -> Error allocating a new cell.\n");
		return 0;	
	}

	newCell->item = item;
	newCell->previous = list->last;
	newCell->next = NULL;

	if(!list->length){
		list->first = list->last = newCell;
	}
	else{
		list->last->next = newCell;	
		list->last = newCell;
	}
	list->length += 1;

	return 1;
}

int removes(List *list, ItemT item){
	if(list == NULL){
		fprintf(stderr, "REMOVES Function -> Invalid parameter.\n");
		return 0;
	}

	Cell *walker = list->first;
	while(walker != NULL){
		if(walker->item == item){
			if(list->length == 1){
				list->length--;
				free(list->first);
				list->first = list->last = NULL;

				return 1;
			}
			else if(walker == list->first){
				walker->next->previous = NULL;
				list->first = walker->next;
				list->length--;
				free(walker);

				return 1;	
			}
			else if(walker == list->last){
				walker->previous->next = NULL;
				list->last = walker->previous;
				list->length--;
				free(walker);

				return 1;
			}

			walker->previous->next = walker->next;
			walker->next->previous = walker->previous;
			list->length--;
			free(walker);

			return 1;
		}
		else{
			walker = walker->next;
		}
	}

	return 0;
}

void destroy(List *list){
	if(list == NULL){
		fprintf(stderr, "DESTROY Function -> Invalid parameter.\n");
		return;
	}

	Cell *aux = list->first;
	while(aux != NULL){
		list->first = aux->next;
		free(aux);
		aux = list->first;
	}
	free(list);
}

void printList(List *list){
	if(list == NULL){
		fprintf(stderr, "PRINT LIST Function -> Invalid parameter.\n");
		return;
	}

	Cell *walker = list->first;
	while(walker != NULL){
		printf("%d\n", walker->item);
		walker = walker->next;
	}
}
