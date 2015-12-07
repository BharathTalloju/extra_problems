/*
		Question : Sorted a linked list which is in ascending order but two numbers are changed,
		I mean not in the usual order they need to be
		Ex: 1->2->3->15->10->4->20; O/p:1-2-3-4-10-15-20
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}NODE;

NODE* swap_the_odd_ones(NODE *head){
	NODE *misplaced_node1 = NULL;
	NODE *predecessor_of_misplaced_node1 = NULL;
	NODE *misplaced_node2 = NULL;
	NODE *predecessor_of_misplaced_node2 = NULL;
	
	if(head == NULL){
		return head;
	}
	
	misplaced_node1 = head;
	
	while((misplaced_node1-> data) <= (misplaced_node1-> next-> data)){
		predecessor_of_misplaced_node1 = misplaced_node1;
		misplaced_node1 = misplaced_node1-> next;
	}
	
	predecessor_of_misplaced_node2 = misplaced_node1;
	misplaced_node2 = predecessor_of_misplaced_node2-> next;
	min = misplaced_node2-> val;
	
	while(misplaced_node2){
		if((misplaced_node2-> val) < min){
			break;
		}
		predecessor_of_misplaced_node2 = misplaced_node2;
		misplaced_node2 = misplaced_node2-> next;
	}
	
	if(predecessor_of_misplaced_node1 == NULL){
		// There are only two nodes in the list, swap them both.
		misplaced_node2-> next = misplaced_node1;
		misplaced_node1-> next = NULL;
		
		return misplaced_node2;
	}
	
	predecessor_of_misplaced_node1-> next = misplaced_node2;
	predecessor_of_misplaced_node2-> next = misplaced_node1;
	temp = misplaced_node1-> next;
	misplaced_node1-> next = misplaced_node2-> next;
	misplaced_node2-> next = temp;
	
	return head;
}