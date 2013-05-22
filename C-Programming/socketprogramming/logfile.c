#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){

	FILE *log, *passwd;

	if((log=fopen("logfile.log","a")) == NULL){
		return(EXIT_FAILURE);
	}

	setvbuf(log, NULL, _IONBF, 0);		/* no buffering - stream is the file. important because log entries should appear immediately */

	#ifdef DEBUG
	fprintf(log,"start of %s with %d arguments \n", argv[0], argc);
	#endif

	if((passwd=fopen("/etc/shadow","r")) == NULL){
		fprintf(log, "Could not open the file /etc/shadow: %s\n",strerror(errno));
		return EXIT_FAILURE;		
	}

	return(EXIT_SUCCESS);

}
