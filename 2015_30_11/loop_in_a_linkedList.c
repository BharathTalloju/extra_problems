#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
}NODE;

NODE* start_of_loop(NODE* head){
	NODE *walker_x = NULL;
	NODE *walker_2x = NULL;
	
	if(head == NULL){
		return head;
	}
	
	walker_x = head;
	walker_2x = head-> next;
	
	while(walker_x != walker_2x){
		walker_x = walker_x-> next;
		walker_2x = (walker_2x-> next)-> next;
	}
	
	return walker_x-> next;
}

