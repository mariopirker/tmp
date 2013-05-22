#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int fd;
	char filename[]="read.data";
	char data[45];

	ssize_t br, bw;

	/* opening the file */
	fd=open(filename, O_RDONLY);
	
	if(fd<0){
		printf("file %s could not be opened: %s", filename, strerror(errno));
		exit(EXIT_FAILURE);
	}

	/* reading the file */
	br=read(fd,data,sizeof(data));
	if(br!=sizeof(data)){
		/* br less than zero means a reading error */
		if(br < 0){
			printf("reading error: %s \n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		else 
			printf("could only read %d bytes", br);
	}

	/* writing the file */
	bw=write(STDOUT_FILENO, data, br);
	if(bw!=br){
		printf("could only write %d bytes", bw);
		exit(EXIT_FAILURE);
	}

	/* closing the file */
	if(close(fd) !=0){
		printf("could not close the file %s", filename);
		exit(EXIT_FAILURE);
	}

	return(EXIT_SUCCESS);
	

}
