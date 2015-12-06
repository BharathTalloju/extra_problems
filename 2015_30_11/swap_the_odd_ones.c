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
	
	misplaced_node1 = head;
	
}