#include <stdio.h>
#define MAXOPERANDS 100
#define MAXOPERATORS 100

int main(int argc, char *argv[]){

	char plu='+';
	char min='-';
	char div='%';
	char mul='*';

	char *operands[MAXOPERANDS];
	char *operators[MAXOPERATORS];

	int i=0, j=0;
	int tmp=0;
        int z=0;
        int w=0;
	int *res;


	while(argc > 0 && ((*argv[0]==plu) || (*argv[0] == min) || (*argv [0] == div) || (*argv[0] == mul))){
		*++operands[++i]=*++argv[0];
		--argc;
	}

	*operators=*argv;	

	int x1= *operators[z];
	int x2= *operators[++z];
	switch(*operands[w]){
	case '+':
		if(tmp=0)
			*res=x1+x2;
		else 
			*res=tmp+x1;
			tmp=*res;	
		break;
	case '-':
		if(tmp=0)
			*res=x1-x2;
		else
			*res=tmp-x1;
			tmp=*res;
		break;
	case '*':
		if(tmp=0)
			*res=x1*x2;
		else
			*res=tmp*x1;
			tmp=*res;
		break;

	case '%':
		if(tmp=0)
			*res=x1%x2;
		else
			*res=tmp%x1;
			tmp=*res;
		break;
	}
	

}
