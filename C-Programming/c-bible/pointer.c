#include <stdio.h>

static int array1[5];
static int array2[5];

/* simply swaps to arrays */
void swap(int *px, int *py){
	int temp;
	temp=*px;
	*px=*py;
	*py=temp;
}

/* counts the length of a string */
int mystrlen(char *s){
	int n;
	for(n=0; *s!='\0'; s++) 	/* iterate over list of arrays and always increment pointer by one, stop when reaching \0 */
		n++;
	return n;
}

int mystrlen2(char *s){
	char *p=s;
	
	while(*p != '\0')
		p++;
	return p-s;			/* valid because both point to the same array or object */

}

int main(){
	swap(array1,array2);

	char test[5]="Hallo";

	printf("Die laenge des Strings %s ist: %d", test, (mystrlen(test)-1));
	printf("\n");
}

