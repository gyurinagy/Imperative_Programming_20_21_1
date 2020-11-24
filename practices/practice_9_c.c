#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void swap(char *a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
} 

void reverse(char* str){
    for ( int i  =0;i<strlen(str)/2;++i){
        swap(str+i,str+(strlen(str)-i-1));
    }
}

char* reverse2(char* str){
    char* reversed = calloc(strlen(str)+1,sizeof(char));
    for(int i=0;i<strlen(str);++i){
        reversed[i]=str[strlen(str)-i-1];
    }
    return reversed;
}

int main(){
    char a[] = "Valami string";
    printf("%s\n",a);
    char* b = reverse2(a);
    printf("%s\n%s\n",a,b);
    free(b);
}