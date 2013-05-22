#define ALLOCSIZE 10000 /* size of the available space */

static char allocbuff[ALLOCSIZE];	/* storage array */
static char *allocp = allocbuff;	/* always points to the next free position */

/* allocates n amount of space and returns pointer. if not possible, it returns null */
char *alloc(int n){
	if (allocbuff + ALLOCSIZE - allocp >= n){
		allocp+=n;		/* increment the pointer for the next free position to n */
		return allocp-n;	/* return the pointer for the sub array */
	}
	else
		return 0;
}

void afree(char *p){
	if(p>=allocbuff && p < allocbuff + ALLOCSIZE){
		allocp = p;		
	}
}

int main(){

}
