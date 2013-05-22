#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int user_exists(char *);

int main(int argc, char *argv[]){

	if(argc < 2){
		printf("Please enter your user name \n");
		return EXIT_FAILURE;
	}

	if(! user_exists(argv[1])){
		printf("invalid user name! \n");
		return EXIT_FAILURE;
	}

	printf("User %s exists \n", argv[1]);
	return(EXIT_SUCCESS);

}

int user_exists(char *user){

	int ok=0;
	char buffer[8];

	printf("starting address of ok %x\n", &ok);
	printf("starting address of buf %x\n", buffer);

	/* copy user into buffer */
	/* bad !!! no limitation on length */
	strcpy(buffer,user);

	/* returns null pointer of user does not exist in user db */
	if (getpwnam(buffer))
		ok=1;

	return ok;
	

}
