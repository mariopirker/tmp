#include <stdio.h>	 /* includes the standard i/o functions like printf and getline */
#include <stdlib.h>	 /* includes the EXIT_SUCCESS */
#include <string.h>	 /* includes the strcmp function */
#include <unistd.h>	 /* includes the prototype for _exit() */

void exit_handler(void){
	printf("The exit handler has been called. \n");

}

int main(int argc, char *argv[]){

	/* atexit tries to register the exit handler and retunrs zero if the registration was fine */
	if(atexit(exit_handler)!=0){
		printf("Exit handler could not be registered. \n");
		exit(EXIT_FAILURE);
	}

	printf("...");	/* output will be buffered - no carriage return and so it is not written down immediately */
	
	if(argc > 1){
		/* strcmp compares two strings and returns zero if they are equal */
		if(strcmp(argv[1], "exit") == 0){
			exit(EXIT_SUCCESS);	/* closes all streams and writes all buffers */
		}
		else
			_exit(EXIT_SUCCESS);	/* if they are not equal, the _exit is called and so no exit handler functions are called, buffers won't be written!! */
	}
	
	printf("and..\n");	/* is only called if programm is called without option, because then the program excits before */
	return(EXIT_SUCCESS);

}
