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
   // Inserts nodes of list2 at their correct positions in list1
   NODE* list1_successor = NULL;
   NODE* list2_successor = NULL;
   
   if(head1 == NULL){
     return head2;
   }
   
   if(head2 == NULL){
     return head1;
   }
   
   if(head1-> next == NULL){
     if((head1-> value) <= (head2-> value)){
       //Insert head1 before head2
       head1-> next = head2;
       return head1;
     }
     
     else{
       list2_successor = head2-> next;
       
       if(list2_successor == NULL){
         //list2 has only one node
         head2-> next = head1;
         return head2;
       }
       
       while(list2_successor != NULL){
         
       }
     }
   }
   
   
   
 }