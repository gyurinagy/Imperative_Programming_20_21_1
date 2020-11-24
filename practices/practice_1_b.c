#include "stdio.h"

int main(){

float num1, num2;
printf("Enter two numbers\n");
scanf("%f %f",&num1,&num2);
float result;
result = num1/num2;
printf("%.2f /%.2f = %.2f\n",num1,num2,result);

}
