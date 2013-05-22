#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

	char buf[40];
	printf("address of buf is %x\n", buf);
	printf("please enter a string\n");
	gets(buf);		/* reads from stdin until new line comes */
	
	printf("the buffer contains %s\n",buf);
	
}

