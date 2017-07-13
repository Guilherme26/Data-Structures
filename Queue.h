#include <stdlib.h>
#include <stdio.h>

/*
	Just Remembering some notations
	Θ -> Theta is a notation that is used to describe tight bound to the behaviour of a function F(n), i.e,
			claims that there is two constants k and k', a number M and a function G(n), such that 
			kG(n) <= F(n) <= k'G(n) for all n >= M.
	Big-o or O -> This is a notation that shows an upper bound that asymptotically domains the algorithm 
					execution time. Is right to say that a function F(n) is assymptotically dominated by 
					G(n) if there is a constant k and a number M such that F(n) <= kG(n) for all n >= M.
*/


/*
	A Queue is a kind of data struct with the following characteristics:
		°Its size is variable
		°When removes an item, the rest of the data do not need to be moved
		°The data do not need to be stored sequentially on memory
		°Follows the FIFO model - First In First Out
	An infinity of ways to implement this structure is possible, but the chosen one, in this case, has a 
	Cell composed by a pointer to the next cell, and a variable to keep the item value. A Queue variable 
	is responsible to save the first and the last cell addresses and the length of the whole structure.
	This data structure is often used in scenarios where the input order matters. We can conceive this 
	resource like a bank queue, where who comes first is attended first. But like in real life, there is 
	some cases where people have priority on attendance, for example, a pregnant woman or an elder person.
	This scenario can be represented in computation with a Priority Queue, that is a little variation of 
	this implementation.
*/

//This definition is meant to facilitate changes through the code
typedef int ItemT;

typedef struct cell{
	ItemT item;
	struct cell *next;
} Cell;

typedef struct {
	Cell *first;
	Cell *last;
	int length;
} Queue;


/*
	This function does a dynammic allocation and then returns the memory address to the caller. The cost 
	of the procedure is Θ(1).
*/
Queue *doEmptyQueue();

/*
	In this implementation, an item can only be added at the end of the structure. Diferently from Lists in 
	this kind of data structure this is a property. Given that the address to the last element is known,
	we can access it with one instruction, so the time complexity to this procedure is described 
	by Θ(1). The return value represents the status of the procedure, i.e, returns a TRUE state in cases 
	that the procedure occurred correctly and FALSE otherwise.
*/
int adds(Queue *queue, ItemT item);

/*
	A remove procedure must remove the first item of the structure, but the first position is known and can be 
	accessed with one instruction, which means that the function has a complexity order of Θ(1). The return 
	value represents the status of the procedure, i.e, returns a TRUE state in cases that the procedure occurred 
	correctly and FALSE otherwise.
*/
int removes(Queue *queue);

/*
	This method must be used at the end of the using of the data structure. Its function is to free every cell 
	allocated to the structure and, consecutively, delete the queue. Consider 'n' as the number of items, this 
	procedure has complexity order of Θ(n).
*/
void destroy(Queue *queue);

/*
	This method is used to print all the 'n' items of the structure. So, the complexity order is Θ(n).
*/
void printQueue(Queue *queue);