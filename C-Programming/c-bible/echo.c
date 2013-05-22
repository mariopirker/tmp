#include <stdio.h>

/* argv is a pointer to an array of pointers and argc represents the length of the array 
   argv[0] can never be null because it is always the name of the command itself */
int main(int argc, char *argv[]){

	int i;
	
	for(i=1; i<argc; i++)
		printf("%s%s", argv[i], (i < argc-1) ? " ":"");
	printf("\n");
	return 0;
}


