// practice_12.c

#include "stdio.h"
#include "stdlib.h"

struct Element{
    int _weight;
    struct Element* _next;
};

struct Element* top;

void init(){ top=0; }
int isEmpty(){ return top==0; }
int peek(){ return (top==0) ? -1 : top->_weight; }

void push(int weight){
    struct Element* tmp = top;
    top = malloc(sizeof(struct Element));
    top->_next = tmp;
    top->_weight = weight;
}

void pop(){
    if(!isEmpty()){
        struct Element* tmp=top;
        top=top->_next;
        free(tmp);
    }
}

void copyTop(){
    struct Element* tmp = top;
    top = malloc(sizeof(struct Element));
    top->_next = tmp;
    top->_weight = tmp->_weight;
}

void delete(struct Element* a){
    if(a->_next!=0){
        delete(a->_next);
        free(a);
    }else
        free(a);
    
}

int main(){

    init();  
    push(2);
    push(3);
    push(10);

    struct Element*tmp = top;
    while(tmp!=0){
        printf("%d -> ",tmp->_weight);
        tmp=tmp->_next;
    }
    delete(top);

}