#include "stdio.h"

#define PI 3.1415

int main(){

	int a,b,r;
	printf("Enter the two side of a rectangle and the radius of a circle: \n");
	scanf("%d %d %d",&a,&b,&r);
	printf("Area of the rectangle: %d\n",(a*b));
	printf("Area of the circle: %.2f\n",(r*PI));


}
