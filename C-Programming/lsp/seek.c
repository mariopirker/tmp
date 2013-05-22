#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main(void){

	int fd;
	fd=open("/u3/g/kell3040/C-Programming/lsp/seek.test",O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

	off_t ret;

	//ret=lseek(fd, (off_t) 1815, SEEK_SET);	/* current file position is set to 1815 */
	ret=lseek(fd, (off_t) 1815, SEEK_END); 

	if(ret==(off_t) -1){
		if(errno==EBADF)
			perror("ERROR");
	}
	printf("the new file position is %d\n", (int) ret);

}
