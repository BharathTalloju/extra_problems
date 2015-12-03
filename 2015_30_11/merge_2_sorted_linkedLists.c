/* 
  Program to merge two sorted linked lists, so that the resultant linked list is also sorted.
  
  Assumption : The lists are sorted in ascending order.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct node{
   int value;
   struct node *next;
 }NODE;
 
 NODE* merge_linked_lists(NODE *head1, NODE *head2){
  NODE* result = NULL;
  
  if(head1 == NULL){
    return head2;
  }
  if(head2 == NULL){
    return head1;
  }
  
  if((head1-> value) <= (head2-> value)){
    result = head1;
    head1 = head1-> next;
  }
  else{
    result = head2;
    head2 = head2-> next;
  }
  
  while(head1 && head2){
    if((head1-> value) <= (head2-> value)){
      result-> next = head1;
      result = head1;
      head1 = head1-> next;
    }
    else{
      result-> next = head2;
      result = head2;
      head2 = head2-> next;
    }
  }
  result-> next = NULL;
  if(head1){
    result->next = head2;
  }
  if(head2){
    result-> next = head1;
  }
  
  
 }
 
 int main(){
	NODE *head;
  NODE *head1,*head2;
	NODE list1[4],list2[5];
	int i;
	
	for(i = 0 ; i < 4 ; i++){
		(list1[i]).value = i;
		(list1[i]).next = &(list1[i+1]);
	}
	(list1[3]).next = NULL;
	head1 = list1;
	
	
	//printf("Median of list1 = %f\n",median_of_linkedList(head));
	
	for(i = 0 ; i < 5 ; i++){
		(list2[i]).value = i;
		(list2[i]).next = &(list2[i+1]);
	}
	(list2[4]).next = NULL;
	head2 = list2;
	
  head = merge_linked_lists(head1,head2);
	//printf("Median of list2 = %f",median_of_linkedList(head));
  
  while(head){
    printf(" %d-> ",head-> value);
    head = head-> next;
  }
	
}