#include <stdio.h>
#include <stdlib.h>

int largest_sub_array(int *arr, int len){
	int *right_array;
	int i, sum = 0;
	int max = 0;
	
	printf("\nThe array to be checked is : ");
	for(i = 0 ; i < len ; i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
	
	//Check if the Size of the array can be reduced from right.
	for(i = 0 ; arr[i] < 0 ; i++);
	if(i > 0){
		return largest_sub_array((arr+i), len-i);
	}
	
	//Check if the size of the array can be reduced from left;
	for(i = len-1 ; arr[i] >= 0 ; i--);
	if(i > (len-1)){
		return largest_sub_array(arr, i+1);
	}
	
	right_array = (int*) calloc(len, sizeof(int));
	//Initialize the right_array
	for(i = len-1 ; i >= 0 ; i--){
		
		if(arr[i] < 0){
			right_array[i] = sum;
			sum = 0;
		}
		else{
			sum += arr[i];
		}
		 
	}
	
	//An element is an ally if it helps in increasing the overall sum i.e. it's right_array[i] > -arr[i], even though the element is itself negative
	//Otherwise it is an enemy. 
	sum = 0;
	max = 0;
	for(i = 0 ; i < len ; i++){
		if(arr[i] >= 0){
			sum += arr[i];
		}
		else{
			if(is_an_ally(right_array,arr, i)){
				sum += arr[i];
			}
			else{
				//end the sub-array
				if(sum > max){
					max = sum;
				}
				sum = 0;
			}
		}
	}
	
	if(sum > max){
		max = sum;
	}
	return max;
	
	
}

int is_an_ally(int *right_array,int *arr, int index){
	if((right_array[index] + arr[index]) >= 0){
		return 1;
	}
	return 0;
}

//Test Driver

int main(){
	int arr[] = {1,2,3,5,-10,20,40};
	int len = 7;
	
	printf("Sum = %d",largest_sub_array(arr, len));
	 
}

