#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNUMBER 100000

int main(){
	char pid[MAXNUMBER];

	fork();
	fork();
	fork();
	fork();

	sprintf(pid, "PID= %d\n",getpid());
	write(STDOUT_FILENO, pid, strlen(pid));
	exit(0);

}
