#include <stdio.h>

/* this approach is slightly different because we simply iterate over the array of pointers to characters */
int main(int argc, char *argv[]){

	while(--argc >0){
		printf("%s%s", *++argv, (argc > 1) ? " ": "");

	}
	printf("\n");
	return 0;

}
