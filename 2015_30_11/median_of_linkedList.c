/*
			Median of a sorted Linked List
	 * Function returns the value of the median, 0 in case the list is empty
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	float value;
	struct node *next;
}NODE;

float median_of_linkedList(NODE* head){
	NODE *walker_x = NULL;	//checks every node
	NODE *walker_2x = NULL;	//checks every alternative node
	
	walker_x = head;
	walker_2x = head;
	
	//																																while(head){
	//																																	printf("%f -> ",head -> value);
	//																																	head = head->next;
	//																																}
	
	if(walker_x == NULL){
		//List is empty
		return 0;
	}
	
	while(1){
		walker_2x = walker_2x -> next;
		if(walker_2x == NULL){
			//Odd no. of nodes
																																		//printf("\nreturnong %f\n",walker_x -> value);
			return walker_x -> value;
		}
		
		walker_2x = walker_2x -> next;
		if(walker_2x == NULL){
			//even no. of nodes
			float median;
			
			median = ((walker_x -> value) + (walker_x -> next)->value ) / 2;
																																			//printf("\nReturning %f",median);
			return median;
		}
		
		walker_x = walker_x -> next;
	}

}


int main(){
	NODE *head;
	NODE list1[4],list2[5];
	int i;
	
	for(i = 0 ; i < 4 ; i++){
		(list1[i]).value = i;
		(list1[i]).next = &(list1[i+1]);
	}
	(list1[3]).next = NULL;
	head = list1;
	
	
	printf("Median of list1 = %f\n",median_of_linkedList(head));
	
	for(i = 0 ; i < 5 ; i++){
		(list2[i]).value = i;
		(list2[i]).next = &(list2[i+1]);
	}
	(list2[4]).next = NULL;
	head = list2;
	
	printf("Median of list2 = %f",median_of_linkedList(head));
	
}