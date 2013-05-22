#include <stdio.h>
#include <stdlib.h>

void swap(int *, int, int);

void main(void){
	int test[6]={1,2,4,3,5,6};
	int x,y;
	
	printf("before: \n");
	printf("%s",test);
	putchar('\n');
	swap(test,0,1);
	printf("after: \n");
	printf("%s",test);
        putchar('\n');

}

void swap(int v[], int i, int j){
	int temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;

}
