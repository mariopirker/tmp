#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "hacking-networking.h"

int main(int argc, char *argv[]){

	int sockfd;
	struct hostent *host_info;
	struct sockaddr_in target_addr;
	unsigned char buffer[4096];
	
	if (argc < 2){
		printf("Usage: %s <hostname>\n",argv[1]);
	}

	/* tries to resolve the hostname. if it failes, a null pointer is returned */
	if((host_info=gethostbyname(argv[1]))==NULL){
		printf("Could not resolve hostname %s",argv[1]);
	}

	/* creates a usual tcp socket for internet protocol family */
	if((sockfd=socket(PF_INET, SOCK_STREAM,0))==0){
		printf("Error creating socket\n");
	}
	
	target_addr.sin_family=AF_INET;		/* sets the host byte order */
	target_addr.sin_port=htons(80);		/* changes the integer port number from host byte order into network byte order */
	target_addr.sin_addr = *((struct in_addr *) host_info->h_addr);		/* sets the address we are trying to connect. the information is received from hostent struct */
	memset(&(target_addr.sin_zero),'\0',8);		/* padding to zero */

	/* connect function call on socket tries to connect 
	see http://linux.die.net/man/2/connect */
	if(connect(sockfd, (struct sockaddr *)&target_addr, sizeof(struct sockaddr)) == -1){
		printf("Error when connecting to the remote server\n");
	}

	send_string(sockfd, "HEAD / HTTP/1.0\r\n\r\n");

	while(recv_line(sockfd, buffer)){
		/* strncasecmü is a string comparsion functon from string.h that compares the first n bytes of the two strings, ignoring capit. 
		   it retunrs 0 on success. If it found that string, it will remove that and print out everything after that */
		if(strncasecmp(buffer, "Server:",7)==0){
			printf("The webserver for the hostname %s is %s\n", argv[1], buffer+8);
			exit(0);
		}
	}
	printf("Server line not found\n");
	exit(1);

}
