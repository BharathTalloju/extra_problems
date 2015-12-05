#incude <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

NODE* add_node_after(int value, NODE *head){
	NODE *new = NULL;
	
	new = (NODE*)malloc(sizeof(NODE));
	new-> data = value;
	
	if(head){
		
		new-> next = head-> next;
		head->next = new;
		
	}
	
	return new;
}