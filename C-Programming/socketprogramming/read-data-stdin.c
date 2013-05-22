#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int fd;
	char data[45];

	ssize_t br, bw;

	/* reads bytes from standard input */
	br = read(STDIN_FILENO, data, sizeof(data));
	if(br!=sizeof(data)){
		if(br <0){
			printf("reading error: %s", strerror(errno));
			exit(EXIT_FAILURE);		
		}
		printf("could only read %d bytes", br);
	}

	/* writes the bytes to the standard output */
	bw = write(STDOUT_FILENO, data, br);
	if (bw!=br){
		printf("could only write %d bytes", bw);
		exit(EXIT_FAILURE);
	}	
	
	return(EXIT_SUCCESS);

}
