#include <stdio.h> 

void swap(int *, int*);

int main(void){

	int x=1, y=2, z[10];
	int *xp;

	xp = &x;	/* xp now points to the address of x */
	printf("pointer xp now points to %d and the value of %d \n", xp, x);	

	y=*xp;		/* y is now the value of the address of xp */
	printf("y has no the value %d (compare %d) \n", y, *xp);

	*xp=0; 		/* sets also x to zero */
	printf("the value that xp is pointing to (previos x) is now %d \n", x);

	xp=&z[10];	/* with this assignment, xp now points to the address of the value of z[10] */

	int *pa;
	int *pb;
	int a=5, b=10;
	
	printf("a has the value %d and b has the value %d \n", a,b);

	pa=&a;
	pb=&b;
	
	swap(pa,pb);
	
	printf("a has the value %d and b has the value %d \n", a,b);

}


void swap(int *pa, int *pb){

	int temp;
	
	temp=*pa;
	*pa=*pb;
	*pb=temp;

}
