#include <stdio.h>


void swap( int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



int main(){

    int a = 5;
    int b = 3;
    swap(&a,&b);
    
    printf("%d, %d\n", a,b);
} 
