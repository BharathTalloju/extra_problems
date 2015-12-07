/*
Input : x,y and n
Output : Return the nth element, after merging the tables of x and y, and removing the duplicates.
*/

#include <stdio.h>
#include <stdlib.h>

int nth_element_of_merged_table(int x, int y, int n){
	int *table_x = NULL;
	int *table_y = NULL;
	int result;
	
	if(n == 0){
		return 0;
	}
	
	if(x == y){
		return n * x;
	}
	
	table_x		 = (int*) calloc(n, sizeof(int));
	table_y = (int*) calloc(n, sizeof(int));
	
	construct_table(table_x, x, n);
	construct_table(table_y, y, n);
	
	return nth_number_of_merge_table(table_x, table_y, n);
}

void construct_table(int *table, int num, int len){
	int i ;
	
	for(i = 0 ; i < len ; i++){
		table[i] = (i+1) * num;
	}
	
}

int nth_number_of_merge_table(int *table_x, int *table_y, int len){
	int i = 0,j = 0;
	int w = -1;
	int merged_table[len];
	
	while(w != len-1){
		if(table_x[i] == table_y[j]){
			merged_table[++w] = table_x[i];
			i++;
			j++;
		}
		
		else if(table_x[i] < table_y[j]){
			merged_table[++w] = table_x[i];
			i++;
		}
		
		else if(table_y[j] < table_x[i]){
			merged_table[++w] = table_y[j];
			j++;
		}
		
	}
	
	return merged_table[w];
}

//Test Driver

int main(){
	
	printf("%d",nth_element_of_merged_table(3,4,12));
}
