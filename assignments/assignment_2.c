#include <stdio.h>

int collatz(int n,int* i){
    if(n==1) printf("%d ",n);
    else printf("%d, ",n);
    (*i)++;

    if(n%2==1 && n>1){
        return collatz(n*3+1,i);
    }else if(n>1){
        return collatz (n/2,i);
    }
    return 1;
}

int main(){

    int n;
    
    do{
        scanf("%d",&n);
    }while(n<1);
    int i = 0;
    int a = collatz(n,&i);
    printf("\n%d\n",i);
}
