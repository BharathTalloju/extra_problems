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
  NODE *temp;
  
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
  temp = result;
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
    result->next = head1;
  }
  if(head2){
    result-> next = head2;
  }
  
  return temp;
  
  
 }
 
 //Test Driver
 int main(){
   int i;
   NODE *head1 = NULL;
   NODE *head2 = NULL;
   NODE *result = NULL;
   
	NODE list1[] = {
    {1,NULL},
    {2,NULL},
    {4,NULL},
    {7,NULL}
  };
  
  NODE list2[] = {
    {0,NULL},
    {3,NULL},
    {3,NULL},
    {5,NULL},
    {5,NULL},
    {9,NULL}
  };
  
  for(i = 0; i<3 ; i++){
    (list1[i]).next = &(list1[i+1]);
  }
  
  result = list1;
  printf("\nList 1 :  ");
  while(result){
    printf("%d-> ",result-> value);
    result = result-> next;
  }
  
  for(i = 0 ; i<5 ; i++){
    (list2[i]).next = &(list2[i+1]);
  }
  result = list2;
  printf("\nList2 :  ");
  while(result){
    printf("%d-> ",result-> value);
    result = result-> next;
  }
  
  
  head1 = list1;
  head2 = list2;
  
  result = merge_linked_lists(head1, head2);
  
  printf("\nResult :  ");
  while(result){
    printf("%d-> ",result-> value);
    result = result-> next;
  }
  
	
}