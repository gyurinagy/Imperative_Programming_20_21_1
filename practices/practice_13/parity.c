#include "parity.h"
#include "stdio.h"

int InitParityArray(ParityArray *p,unsigned max){
    p->max_size=max;
    p->even_idx = 0;
    p->odd_idx = max-1;
    p->array = calloc(max,sizeof(int));
    if(p->array==NULL)return 1;
    // for(int i = 0;i<max;++i){
    //     p->array[i]=-1;
    // }
    return 0;
}

int InsertIntoParityArray(ParityArray* p,int insert){
    if(p->even_idx > p-> odd_idx)return -1;
    if(insert%2==0){
        //if(p->array[p->even_idx] != -1) return 1;
        p->array[p->even_idx] = insert;
        p->even_idx++;
    }else {
        //if(p->array[p->odd_idx] != -1) return 1;
        p->array[p->odd_idx] = insert;
        p->odd_idx--;
    }
    return 0;
}

void PrintParityArray(ParityArray* p){
    // for(int i = 0;i<MAX_ARRAY_SIZE;++i){
    //     if(p->array[i]!=-1) printf("%d ",p->array[i]);
    // }
    for(int i  =0;i<p->even_idx;++i){
        printf("%d ",p->array[i]);
    }
    for(int i  =p->odd_idx+1;i<p->max_size;++i){
        printf("%d ",p->array[i]);
    }
    printf("\n");
}

void DisposeParityArray(ParityArray* p){

    p->even_idx  =0;
    p->odd_idx = 0;
    p->max_size = 0;
    free(p->array);
    p->array=0;

}
