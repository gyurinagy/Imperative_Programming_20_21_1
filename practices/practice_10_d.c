#include "stdio.h"

int add_two_numbers(int x,int y){
    return x+y;
}
// függvény pointer 
void sum(int* vector, int size, int*result, int(*add)(int a,int b)){
    for(int i = 0; i < size-1; i+=2){
            *result+=(*add)(vector[i],vector[i+1]);
    }
}

int main(){

    int vector[5] = {0,1,2,3,4};
    int result=0;
    sum(vector, sizeof(vector)/sizeof(int), &result, add_two_numbers);
    printf("%d\n",result);
}