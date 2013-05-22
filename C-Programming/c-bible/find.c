#include <stdio.h>
#include <string.h>
#include "book.h"
#define MAXLINE 1000

/* function prototypes */
int mygetline(char *line, int max);
int findpattern(char *);

static char line[MAXLINE];
static int found=0;

main(int argc, char *argv[]){
	char line[MAXLINE];
	long lineno;
	int c, except=0, number=0,found=0;

	while(--argc > 0 && (*++argv)[0] == '-')
		while(c=*++argv[0])
		switch(c){
			case 'x':
				except=1;
				break;
			case 'n':
				number=1;
				break;
			default:
				printf("./find: illegal option %c\n",c);
				argc=0;
				found=-1;
				break;
		}
	if(argc!=1)
		printf("Usage: ./find -x -n pattern\n");
	else
		while(mygetline(line, MAXLINE) > 0){
			lineno++;
			if((strstr(line, *argv) != NULL) != except){
			if(number)
				printf("%ld:", lineno);
			printf("%s",line);
			found++;
			}
		}

}

/* prints out the lines that pattern pattern from the first function argument when called the programm */
int findpattern(char *arg){

	while(mygetline(line, MAXLINE) >0){
	/* strstr strstr liefert einen Zeiger an die Stelle, an der der Anfang der Teilzeichenkette gefunden wurde oder NULL falls er nicht gefunden wurde */
	if(strstr(line,arg) != NULL){
                                printf("%s", line);
                                found++;

                }
        }
	return found;
	

}


