#include <stdio.h>

/* calculates the greates common divisor for two given numbers */
int gcd(int, int);

int main(){

	int zahl1;
	int zahl2;
	int result;

	printf("Bitte geben Sie Zahl 1 ein: \n");
	scanf("%i",&zahl1);
	printf("Bitte geben Sie Zahl 2 ein: \n");
	scanf("%i",&zahl2);

	/* we exploit the fact that gcd(a,b)=gcd(b,a) */
	if(zahl1<zahl2)
		result=gcd(zahl2,zahl1);
	else
		result=gcd(zahl1,zahl2);

	printf("Der ggT von %d und %d ist %d \n", zahl1, zahl2, result);


}

/* calculates the gcd */
int gcd(int z1, int z2){

	if(z2!=0){
		int tmp1=z2;
		int tmp2=(z1 % z2);
		return gcd(tmp1,tmp2);
	}	
	return z1;
}
