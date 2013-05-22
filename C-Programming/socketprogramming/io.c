#include <stdio.h>
#include <stdlib.h>

int main(void){

	char buf[40];
	int c;
	FILE *file;

	file=fopen("test.txt","r");
	if(file!=NULL){
		while((c=fgetc(file)) != EOF)
			putchar(c);
	}
	else{
		printf("Could not read file \n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}
