#include <stdio.h>
#include <unistd.h>
#include <sys/poll.h>

#define TIMEOUT 5 

int main(void){

	struct pollfd fds[2];
	int ret;

	/* watch stdin for input */
	fds[0].fd=STDIN_FILENO;
	fds[0].events=POLLIN;

	/* watch stdout for the ability to write */
	fds[1].fd=STDOUT_FILENO;
	fds[1].events=POLLOUT;

	/* now we are ready and start poll */
	ret=poll(fds,2,TIMEOUT*1000);

	/* if the retur value is less than 0 it is an error */
	if(ret==-1)
		perror("poll");
	
	if(!ret)
		printf("%d seconds elapsed \n",TIMEOUT);

	/* revents specify always the outcome of the poll call */
	if(fds[0].revents & POLLIN)
		printf("stdin is readable \n");

	if(fds[1].revents & POLLOUT)
		printf("stdout is readable \n");

	return 0;
}
