#include <stdlib.h>
#include <stdio.h>

int numcmp(char *, char *);

int main(void){

	char *buf="42Test";
	char *buf2="10Testewew";

	int res;
	res=numcmp(buf,buf2);
	printf("the result is %d\n",res);

}

int numcmp(char *s1, char*s2){

	double v1,v2;
	
	/* atof stops reading as soon a non numerical character has been read */
	v1=atof(s1);	/* returns string into a double */
	v2=atof(s2);

	if (v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else 
		return 0;

}
