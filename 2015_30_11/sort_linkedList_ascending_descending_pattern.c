#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

void swap_the_odd_ones(NODE *head){
	NODE *walker = head;
	NODE *from = NULL;
	NODE *to = NULL;
	NODE *temp = NULL;
	
	
	if(walker == NULL){
		return;
	}
	if(walker-> next == NULL){
		return;
	}
	
	if(walker){
		
		if((walker-> data) <= (walker-> next-> data)){
			
			while((walker-> data) <= (walker-> next-> data)){
				
				walker = walker-> next;
				
				if(walker-> next == NULL){
					
					return;
					
				}
				
			}
			
			from = walker;
			while((walker-> data) >= (walker-> next-> data)){
				walker = walker-> next;
				
				if(walker-> next == NULL){
					
					return;
					
				}
			}
			
			to = walker;
			temp = to-> next;
			
			reverse_linkedList_from_to(from,to);
			
			from-> next = temp;
		}
	}
	
}

void reverse_linkedList_from_to(NODE *from, NODE *to){
	if(head == to ){
		return;
	}
	if((head-> next) == to){
		return;
	}
	
	reverse_linkedList(head-> next, to);
	
	(head-> next)-> next = head; 
	if(flag){
		head-> next = NULL;
	}
}