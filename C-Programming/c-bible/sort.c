#include <stdio.h>
#include <string.h> 

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(){
	int nlines;

	if ((nlines=readlines(lineptr, MAXLINES)) >=0){
		qsort(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		return 0;
	}
	else {
		printf("error: the input is too big for sorting");
		return 1;
	}
}

#define MAXLEN 1000
int mygetline(char *,int);
//char *alloc(int);

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines=0;
	while((len = mygetline(line, MAXLEN)) > 0){
		if(nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++]=0;
		}		
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	int i;

	for(i=0; i < nlines; i++){
		printf("%s\n", lineptr[i]);
	}
}

void qsort(char *v[], int left, int right){

	int i, last;
	void swap(char *v[], int left, int right);	/* function prototype */

	if(left >= right)
		return;
	swap(v, left, (left+right)/2);
	last=left;

	for(i=left+1;i<right;i++){
		if((strcmp(v[i],v[left]) < 0)) 	/* returns value < 0 if elem1 is lexicographical smaller than elem2 */
			swap(v,++last,i);
		swap(v,left,last);
		qsort(v,left,last-1);
		qsort(v,last+1,right);		
	}
}

void swap(char *v[], int i, int j){

	char *temp;
	
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;

}
	
