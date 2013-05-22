#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5	/* select timeout in seconds */
#define BUF_LEN 1024 	/* read buffer in bytes */

int main(void){
	
	struct timeval tv;	/* timeout parameter is a pointer to timeval structure contain tv_sec and tv_usec */
	fd_set readfds;
	int ret;

	/* wait on stdin for input data */
	FD_ZERO(&readfds);		/* this call removes all fds from a set */
	FD_SET(STDIN_FILENO,&readfds);	/* adds the FD for stdin to the set */

	/* sets the timeout to 5 seconds */
	tv.tv_sec=TIMEOUT;
	tv.tv_usec=0;

	/* all right, now we can block */
	/* first element of select is always the highfest fd +1 */
	ret = select(STDIN_FILENO +1, &readfds, NULL, NULL, &tv);
	if(ret==-1){
		perror("select");
		return 1;
	}
	else if(!ret){
		printf ("%d seconds elapsed.\n",TIMEOUT);
		return 0;
	}

	if(FD_ISSET(STDIN_FILENO,&readfds)){
		char buf[BUF_LEN+1];
		int len;

		len = read(STDIN_FILENO, buf, BUF_LEN);
		if(len==-1){
			perror("read");
			return 1;
		}
	}

}
