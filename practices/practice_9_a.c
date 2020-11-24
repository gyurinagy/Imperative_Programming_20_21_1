#include "stdio.h"
#include "stdlib.h"

// void* -> bármilyen pointer lehet
// void* malloc()
// ha nem sikerül lefoglalni a területet nullpointerrel tér vissza

// a calloc(10,sizeof(int)) mindenképpen 0-ra inicializálja az elemeket
// realloc(b,20 * sizeof(int))
// ha nem talál elég helyet akkor nullpointerrel tér vissza

int main(){
    int* a = malloc(sizeof(int));
    if(a==NULL)        return -1;
    
    *a = 2;
    int *b = calloc(10,sizeof(int));
    int *tmp = realloc(b,20*sizeof(int));
    if(tmp!=NULL){ 
        b=tmp;
    }
    free(a);
    free(b);
}