#include <stdio.h>

static char daytab[2][13]={
	{0,31,28,31,30,31,30,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,30,31,30,31}};

int day_of_the_year(int year, int month, int day){

	int i, leap;
	
	leap= (year%4==0) && (year%100 !=0) || (year%400==0);

	for(i=1;i<month;i++){
		day+=daytab[leap][i];

	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){

	int i, leap;
	leap= (year%4==0) && (year%100 !=0) || (year%400==0);

	for(i=1; yearday > daytab[leap][i]; i++)
		yearday-=daytab[leap][i];
	
	*pmonth=i;
	*pday=yearday;

}

/* returns the name of the given month by number */
char *month_name(int n){

	static char *name[]={"Invalid month", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	return (n < 1 || n > 12) ? name[0] : name[n];


}

int main(void){

	char *january=month_name(1);
	printf("the name of the month is %s \n", january);
}

