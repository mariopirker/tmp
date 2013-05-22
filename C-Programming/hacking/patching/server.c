#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>		/* used for string manipulation functions and memset */
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 7890 	/* that is the port where the client is connecting to */

/* function prototype that prints out the buffer in clear text */
void printbuffer(const unsigned char *, const unsigned int);

int main(){

	int sockfd, new_sockfd;	/* server is listening on sockfd, new connections are coming on new_sockfd */
	struct sockaddr_in host_addr, client_addr;
	socklen_t sin_size;
	int recv_length=1, yes=1;
	char buffer[1024];


	/* tries to create a Internet Protocol Socket in stream mode (TCP), last option is zero because there is only one proto in the PF_INET prot
           family */
	if((sockfd=socket(PF_INET, SOCK_STREAM,0)) == -1){
		printf("can't create tcp in socket");
	}

	/* changes option of the socket: SO_REUSEADDR allows to reuse a given address for binding.
	   Without that, if a program already listens on that, it will not be able to rebinnd 
	   second argument specifiys the socket option we are setting (this is a socket option and so SOL_SOCKET) 
           third arguments provides the input to what we shall set the socket and the last one is the lenght */
	if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR, &yes, sizeof(int)) == -1){
		printf("error setting socket option SO_REUSE_ADDR");
	}

	host_addr.sin_family=AF_INET;		/* host byte order */
	host_addr.sin_port=htons(PORT);		/* changes port number into network byte order */
	host_addr.sin_addr.s_addr=0;		/* set the source ip, fill with my ip automatically when it is set to 0 */
	memset(&(host_addr.sin_zero),'\0',8); 	/* padding to zero */
	memset(buffer,'\0',1024);

	/* this call binds the socket to the current ip address on port 7890 */
	if(bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1){
		printf("socket bind failed");
	}

	/* the listen call tells the socket for listen on incoming connections */
	if(listen(sockfd,5)==-1){
		printf("cannot listen on socket");
	}
	/* IMPORTANT: listen function places all incoming connections into a backlog queue until an accept() call accepts the connections */

	/* everything is prepared, we are now ready to accept connections */
	while(1){
		sin_size=sizeof(struct sockaddr_in);
		/* accept actually accepts new connections, that is needed so the initial socket can accept new connections
		   the new fd is used for communicate with the clients */
		new_sockfd=accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
		if(new_sockfd==-1){
			printf("error in accepting new connections");
		}	
		/* inet_ntoa is needed to convert network address to ASCII format and ntohs converts port number to integer */
		printf("server got connection from client ip %s on source port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
		fflush(stdout);
		/* sends welcome message with length 28 to the connected client */
		send(new_sockfd, "Welcome to the test server\n",28,0);
		recv_length=recv(new_sockfd, &buffer, 1024,0);
	
		while(recv_length > 0){
			printf("RECV: %d bytes\n", recv_length);
			fflush(stdout);
			printbuffer(buffer,recv_length);		
			char bufftmp[strlen(buffer)-2];
			strncpy(bufftmp,buffer,strlen(buffer)-2);
			
			recv_length=recv(new_sockfd, &buffer, 1024, 0);
		}
		/* close the client connection */
		close(new_sockfd);
		memset(buffer,'\0',1024);

	}
	return 0;
}

/* prints the content of the buffer */
void printbuffer(const unsigned char *data_buffer, const unsigned int length){

	unsigned char byte;
	unsigned int i, j;

	for(i=0; i < length; i++){
		byte=data_buffer[i];
		printf("%c",byte);
	}

}
