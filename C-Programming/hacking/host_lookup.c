#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>
/* this library file includes the functions for dns resolution. */

int main(int argc, char *argv[]){

	struct hostent *host_info;
	struct in_addr *address;

	if(argc < 2){
		printf("Usage: %s <hostname>\n", argv[0]);
		exit(1);
	}

	/* this function takes a pointer to a string as inout and retunrs a hostent data structure */
	host_info = gethostbyname(argv[1]);
	if(host_info == NULL){
		printf("Could not lookup host %s\n", argv[1]);
	} else {
		/* the hostent struct contains h_addr that returns the 0 element of the address from the name server */
		address = (struct in_addr *) (host_info->h_addr);
		printf("Hostname %s has the address %s\n", argv[1], inet_ntoa(*address));	/* inet_ntoa again takes a struct in_addr as input and retunrs the ip address in ascii */
	}

}
