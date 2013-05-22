#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

/* main function*/
int main (int argc, char *argv[]){

	int fd;		/* file descriptor */
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	/* defines the mode how the file can be accessed through fd */
	char filename[] = "read.data";				
	char text[]="0123\n" "4567\n" "89ab\n" "cdef\n" "ghij\n" "klmn\n" "opqr\n" "stuv\n" "wxyz\n";	/* defines the text that is written */
	ssize_t bw;	/* this is the size that is written */

	fd=open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);	/* opens the file in write / read only mode */
	/* if the fd is smaller one, it could not open the file */
	if(fd < 0){
		printf("Could not open the file %s: %s", filename, strerror(errno));	
		exit(EXIT_FAILURE);
	}

	/* writes the text into the file referenced by fd */
	bw=write(fd, text, strlen(text));
	/* if the length of the text is not equal to the value bw that was returned by write system call, print a message */
	if(bw!=strlen(text)){
		printf("Only %d bytes could have been written to %s", bw, filename);
		exit(EXIT_FAILURE);
	}

	/* closing a fd should normally always return 0, otherwise */
	if(close(fd) !=0){
		printf("Could not close the file %s: %s", filename, strerror(errno));
	
	}

	return(EXIT_SUCCESS);


}
