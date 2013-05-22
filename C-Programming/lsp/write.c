#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/* important, if using O_DIRECT flag when opening the file, the linux paginc cache is bypassed and the data gets directly from userspace buffer to the device */
int main(void){

/* on write success - number of bytes written is returned, otherwise -1 and errno is set */
const char *buf = "My ship is solid!";
ssize_t nr, nr2;
size_t count;
int ret;

count=strlen(buf);

/* opens the file and the file descriptor is returned */
int fd= open("/u3/g/kell3040/C-Programming/lsp/write.test",O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
int fd2=open("/u3/g/kell3040/C-Programming/lsp/write2.test",O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH); 	
/* O_SYNC forces all write operations to be synchronized (fsync() after write) --> but increases wait time and should only be used very seldom! */

nr = write(fd, buf, count);
nr2 = write(fd2, buf, strlen(buf));

/* if the write call returns -1 not all bytes have been written*/
if(nr==-1)
	printf("error writing to the file \n");
/* if the number of written bytes is not equal to the length of the string, we return an error */
else if(nr!=count)
	printf("probably not all bytes have been written \n");
/* looks good, all bytes have been written */
else 
	printf("all bytes have been written \n");

/* file synchronisation */
/* fsync and fdatasync(int fd) writes data to the hard disk (eventually into the write cache of the disk). the call does not return until the hdd returned that the data has been written */
ret=fsync(fd);

/* on success - the call returns 0 */
if(ret==-1){
	/* EINVAL states that the file descriptor is mapped to an object that does not support synchronization */
	if(errno=EINVAL){
		if(fdatasync(fd)==-1)
			perror("fdatasync");
	}else
		perror("fsync");
}

}
