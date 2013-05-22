#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BufferLength 100
#define SERVER "127.0.0.1"
#define SERVPORT 44000


/* function prototype that prints out the buffer in clear text */
void printbuffer(const unsigned char *, const unsigned int);


int main(int argc, char *argv[]){

	int sd, rc, length = sizeof(int);
	struct sockaddr_in serveraddr;
	char buffer[BufferLength];
	char server[255];
	char temp;
	int totalcnt = 0;
	struct hostent *hostp;
	char welcome[4]="RPY";

	/* log file */
	FILE * fp=fopen("test","w");

	/* current time */
	time_t current_time;
	char* c_time_string;
	current_time = time(NULL);

	/* declaration of restart command if the policy service is not running correctly any longer */
	char command[1000];
	sprintf(command,"/bin/ls");

	/* open the socket and get socket descriptor */
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Client-socket error");	
		exit(-1);
	}
	else{
		printf("Client-socket successfully created\n");
		fprintf(fp,"Client-socket successfully started\n");
	}
	strcpy(server, SERVER);
	
	/* set struct sockaddr_in to 0 */
	memset(&serveraddr, 0x00, sizeof(struct sockaddr_in));
	memset(buffer,0x00,sizeof(buffer));
	
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(SERVPORT);
	
	/* connect to the server */ 
	if((rc = connect(sd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))) < 0)
	{
		perror("Connection to server could not be established");
		close(sd);
		exit(-1);
	}
	else
		printf("Connection established \n");

	/* reading data from the server */
	while(totalcnt < BufferLength){
		rc = read(sd, &buffer[totalcnt], BufferLength-totalcnt);
		if(rc < 0)
		{
			perror("Client-read() error");
			close(sd);
			exit(-1);
		}

	
		else if (rc == 0){
			printf("Server program has issued a close()\n");
			close(sd);
			exit(-1);
		}
		else{
			totalcnt += rc;
			printf("RECV: %d bytes\n", totalcnt);
                        fflush(stdout);	
			printbuffer(buffer,totalcnt);

                        if((strncmp(buffer,welcome,strlen(welcome))==0)){
                                printf("client closes socket\n\n");
                                fflush(stdout);
                                close(sd);
                        }
			/* the string returned by the server does not start with the value we suspect - restaring the policy service */
			else{
				system(command);
			}
							
		}
	
	}
	printf("Client-read() is OK\n");
	printf("Echoed data from the f***ing server: %s\n", buffer);
 
	close(sd);
	exit(0);
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

