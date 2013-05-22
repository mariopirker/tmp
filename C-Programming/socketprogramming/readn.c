#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	

}

/* reads n bytes from the file into the buffer */
ssize_t readn(int fd, void *buf, size_t nbyte){

	size_t n;
        ssize_t br;
        char *ptr=buf;	/* with that assignment - they both point to the same address */

	for(n=nbyte; n>0; n-=br, ptr +=br){
		if((br=read(fd, ptr,n)) < 0){
			if(errno=EINTR)		/* Unterbrechnung */
				br=0;
			else 	
				return(-1);
		}
		else if(br==0)
			return(nbyte-n);

	}
	return(nbyte);
	
}

ssize_t writen(int fd, void *buf, size_t nbyte){

	size_t n;
	ssize_t bw;
	char *ptr=buf;

	for(n=nbyte;n>0;n-=bw, ptr+=bw){
		if((bw=write(fd, ptr, n)) <0){
			if(errno==EINTR)
				bw=0;
			else
				return(-1);	/* error */
		}
		else if(bw==0)	/* error */
			return(nbyte-n);		

	}
	
	return(nbyte);


}
