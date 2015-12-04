#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

void reverse_linkedList(NODE* head,int flag){
	
	if(head == NULL ){
		return;
	}
	if((head-> next) == NULL){
		return;
	}
	
	reverse_linkedList(head-> next, 0);
	
	(head-> next)-> next = head; 
	if(flag){
		head-> next = NULL;
	}
	
	
}

//Test Driver
int main(){
	int N = 5;
	NODE *input;
	int i;
	
	input = (NODE*)calloc(N,sizeof(NODE));
	
	for(i = 0 ; i < (N-1) ; i++){
		(input[i]).data = i;
		(input[i]).next = &(input[i+1]); 
	}
	(input[i]).data = i;
	(input[i]).next = NULL;
	
	reverse_linkedList(input,1);
	input = &(input[N-1]);
	while(input){
		printf(" %d-> ",(input-> data));
		input = input-> next;
	}
	
	
}