#include <stdlib.h>
#include <stdio.h>

struct single_list_element{
	void *data;			/* payload */
	struct single_list_elemt *next;	/* pointer to the next element */
};

struct double_list_element{
	void *data;
	struct double_list_element *prev;
	struct double_list_element *next;
};

/* main function */
void main(void){

	printf("Test");

}
