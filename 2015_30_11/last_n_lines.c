#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int print_last_n_lines_of_a_file(char *file_name, int n){
	FILE *fp;
	
	if(!(fp = fopen(file_name,"r"))){
		return;
	}
	
	while(n){
		if(fgetc(fp) == '\n'){
			n--;
		}
		fseek(fp,-2,SEEK_CUR);
		if(!(ftell(fp)))
			break;
 }
 
 if((ftell(fp)))
 	fseek(fp,2,SEEK_CUR);
 while(!feof(fp)){
		printf("%c",fgetc(fp));
 }
}

