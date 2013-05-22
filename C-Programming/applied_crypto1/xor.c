#include <stdio.h>
#include <stdlib.h>

// main method: 
// first parameter: key
// second parameter: input file (to be encrypted)
// third parameter: output file (encrypted)
void main(int argc, char *argv[]){

	FILE *fi, *fo;
	char *cp;
	int c;
	
	if((cp=argv[1]) && *cp!='\0'){
		/* open the input file */
		if((fi = fopen(argv[2],"rb")) != NULL){
			/* open the output file */
			if((fo = fopen(argv[3],"wb")) != NULL){
				while((c = getc(fi)) != EOF){
					if(!*cp)
						cp=argv[1];
					c ^= *(cp++);
					putc(c,fo);
				}
			fclose(fo);
			}
		fclose(fi);
		}
	}
}
