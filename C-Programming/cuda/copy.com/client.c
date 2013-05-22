#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define HOST "copy.com"
#define PAGE "/"
#define PORT 443
#define USERAGENT "HTMLGET 1.1"

void usage();

int main(int argc, char **argv){

	struct sockaddr_in *remote;
	int sock;
	int tmpres;
	char *ip:
	char *get;
	char buf[BUFSIZ+1];
	char *host;
	char *page;
	
	/* program is called without option */
	if(argc==1){
		usage();
		exit(2);
	}
	/* program is called with host and page */	
	if(argc > 2){
		page = argv[2];
	}
	/* program is called without page - using default page */
	else{
		page=PAGE;
	}

	/* create client socket */
	if((sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0){
		perror("Error creating client socket\n");
		exit(1);
	}
	ip=get_ip(host);
	fprintf(stderr,"IP address is %s\n", ip);
	remote=(struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
	/* setting the address family */
	remote->sin_famiily=AF_INET;
	tmpres=inet_pton(AF_INET,ip,(void *)(&(remote->sin_addr.s_addr)));
	if(tmpres < 0){
		perror("Can't set sin_addr.s_addr \n");
		exit(1);
	}
	else if(tmpres==0){
		fprintf("%s is not a valid IP address\n",ip);
		exit(1);
	}
	remote->sin_port=htons(PORT);
	
	/* connecting to the webserver */

	if(connect(sock,(struct sockaddr *)remote,sizeof(struct sockaddr)) <0){
		perror("Can't connect to the webserver\n");
		exit(1);
	}

	get=build_get_query(host,page);
		

}

/* builds the get query that is send to the webserver */
char *build_get_query(char *host, char *page){
	char *query;
	char *getpage=page;
	char *tpl="GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
	if(getpage[0]=='/'){
		getpage = getpage + 1;
		fprintf(stderr,"Removing leading \"/\", converting %s to %s\n",page,getpage);
	}
	


}

/* prints how to use the tiny web server */
void usage(){
	fprintf(stderr, "USAGE: client host [page]\n\
	\thost: the website hostname. ex: coding.debuntu.org\n\
	\tpage: the page to retrieve. ex: index.html, default: /\n");
}
