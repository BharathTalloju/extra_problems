/* 
		Program to add two numbers, whose digits are represented as nodes of  linked list.
		
		Input : pointers to the first nodes of the two linked lists.
		
		Return : pointer to the head node of the resultant linked list.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int digit;
	struct node *next;
}NODE;

NODE *add_linkedList_store_in_result(NODE *list1,NODE *list2){
	char stack1[100],stack2[100];
	int top1= -1 ,top2= -1;
	NODE *result = NULL;
	NODE *temp = NULL;
	int sum;
	int carry = 0;
	
	
	if(list1  == NULL){
		return list2;
	}
	if(list2 == NULL){
		return list1;
	}
	
	
	while(list1 || list2){ // Untill ends of both the linked lists are reached, store the digits of the numbers in their respective stack 
		
		if(list1){
			
			stack1[++top1] = list1-> digit;
			list1 = list1-> next;
			
		}
		
		if(list2){
			
			stack2[++top2] = list2-> digit;
			list2 = list2-> next;
			
		}
		
	}
	
	while((top1 >= 0) || (top2 >= 0)){
		sum = carry;
		
		if(top1 >= 0){
			
			sum += stack1[top1--];
			 
		}
		
		if(top2 >= 0){
			
			sum += stack2[top2--];
			
		}
		
		carry = sum / 10;
		sum = sum % 10;
		
		//Create and insert the new digit before the result list.
		temp = (NODE*) malloc(sizeof(NODE));
		temp-> digit = sum;
		temp-> next = result;
		result = temp;
		
	}
	
	if(carry){
		temp = (NODE*) malloc(sizeof(NODE));
		temp-> digit = carry;
		temp-> next = result;
		result = temp;
	}
	
	return result;
	
}

//Test Driver
int main(){
	NODE *head1,*head2,*head;
	NODE list1[4],list2[5];
	int i;
	
	for(i = 0 ; i < 4 ; i++){
		(list1[i]).digit = i + 6;
		(list1[i]).next = &(list1[i+1]);
	}
	(list1[3]).next = NULL;
	head1 = list1;
	
	
	for(i = 0 ; i < 5 ; i++){
		(list2[i]).digit = i;
		(list2[i]).next = &(list2[i+1]);
	}
	(list2[4]).next = NULL;
	head2 = list2;
	
	head = add_linkedList_store_in_result(head1,head2);
	
	printf("\nList1 :");
	while(head1){
		printf(" %d-> ",head1-> digit);
		head1 = head1-> next;
	}
	
	printf("\nList2 :");
	while(head2){
		printf(" %d-> ",head2-> digit);
		head2 = head2-> next;
	}
	
	printf("\nSum :");
	while(head){
		printf(" %d-> ",head-> digit);
		head = head-> next;
	}
	
}