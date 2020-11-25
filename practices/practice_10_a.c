#include "stdio.h"

#define LARGER(X,Y) (X > Y ? X : Y)
#define PRINT(X) #X
#define FOR(X, FROM, TO, STEP) for (X=FROM;X<TO;X+=STEP)

int main(){
    int i = 2;
    printf("%c\n",LARGER('a','c'));
    PRINT(2);
    LARGER(LARGER('a','b'),'c');
    FOR(i,0,10,2){
        printf("%d ",i);
    }
}