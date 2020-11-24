
#include <stdio.h>

int main(){

	int days ;
	printf("Enter the number of the days: ");
	scanf(" %d",&days);

	int year = days/365;
	int week = (days-(year*365)) / 7;
	int day = days-(year*365)-(week*7);
	printf("Year = %d\nWeek = %d\nDays = %d\n",year,week,day);
	return 0;

}

