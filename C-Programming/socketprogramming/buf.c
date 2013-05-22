#include <stdio.h>
#include <stdlib.h>

int main(void){

	char buf[42];
	
	/* full buffer mode */
	if(setvbuf(stdout,buf, _IOFBF,sizeof buf)){
		perror("failed to change buffer to stdout");
		return EXIT_FAILURE;
	}
	printf("Hel");		/* the buffer contains test now, but nothing written out */
	fflush(stdout);		/* "Hel" is actually written to stdout */

	/* no buffering */
	if(setvbuf(stdout, buf, _IONBF, sizeof buf)){
		perror("failed to change the buffer of stdout");
		return EXIT_FAILURE;
	}
	printf("llo w");

	/* line buffering */
	if(setvbuf(stdout, buf, _IOLBF, sizeof buf)){
		perror("failed to change the buffer of stdout");
                return EXIT_FAILURE;
	}

	printf("orld");		/* orld is in the buffer, but nothing written yet out because line buffer mode */
	//putc(ch,STDOUT);
	putchar('\n');		/* stdout is line bufferedm everything in the buffer is now written out */
			

}
