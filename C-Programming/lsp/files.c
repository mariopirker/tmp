#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void readtest(int);
extern int errno;

int main(void){

	int fd;
	int fd1;
	int fd3;
	fd = open("/u3/g/kell3040/C-Programming/lsp/test1",O_RDONLY | O_TRUNC);
	fd1= open("/u3/g/kell3040/C-Programming/lsp/test2",O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH); 
	fd3= open("/u3/g/kell3040/C-Programming/lsp/test2",O_WRONLY | O_CREAT | O_TRUNC | O_NONBLOCK, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
 
	/* O_WRONLY | O_CREAT | O_TRUNC is so common --> special system call */
	int fd2 = creat("/u3/g/kell3040/C-Programming/lsp/test2", 0644);
	if(fd2 == -1)
		printf("ERROR - creat sys call was not complete \n");     // if file does not exist
        else
                printf("Worked - creat system call was complete\n");    // if file exist

	if(fd1==-1)
		printf("ERROR \n"); 	// if file does not exist
	else 
		printf("Worked \n");	// if file exist

	char buf[BUFSIZ];
	ssize_t nr;

	start:
	nr = read (fd3, buf, BUFSIZ);
	if(nr==-1){
		if(errno=EINTR)
			goto start;	
		if(errno=EAGAIN)
			goto start;
			/* resubmit late */

	}

	readtest(fd1);

}

/* if creat is not system call, that is the "workaround" */
int create (const char *name, int mode){
	return open(name, O_WRONLY | O_CREAT | O_TRUNC, mode);
}

/* this variant is not recommended because we do not know wether an error occured(-1 returned
EOF (return value 0, there is nothing to read).
we should also take into consideration that, if the file is openend without nonblocking, that a read can block I/O */
void readtest(int fd){

	unsigned long word;
	ssize_t nr;
	
	/* reads from the file, and stores it into *buf (second argument) */
	nr = read (fd, &word, sizeof(unsigned long));
	if (nr == -1){
		printf("ERROR - read sys call was not complete \n");
		printf("nr is %l", nr);
	}
	else 
		printf("Worked - read system call was complete\n");

}


int *perfectread(int fd){
	ssize_t ret;
	int *buf;
	unsigned long len;

	/* reads len bytes from the current file position of fd into buf */
	while(len!=0 && (ret = read(fd,buf,len)) != 0){
		/* call is reissued without updating parameters */
		if(errno == EINTR)
			continue;
		perror("read error occured");
		break;
	}
	len -=ret;
	buf +=ret;
	return buf;

}
