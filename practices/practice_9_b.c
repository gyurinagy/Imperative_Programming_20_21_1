#include "stdio.h"
#include "string.h"
#include "stdlib.h"


int main(int argc, char** argv){

    if(argc!=2){
        printf("Kerlek adj meg egy számot\n");
        return -1;   
    }

    int count = atoi(argv[1]);
    char** a = calloc(count,sizeof(char*));

    for(int i  =1;i<argc;++i){
        char* tmp = malloc(255);
        if(tmp==NULL) return -1;
        scanf("%s",tmp);
        a[i] = realloc(tmp,strlen(tmp)+1);
        if(a[i] == NULL) a[i]=tmp;
    }

    for(int i = count -1 ;i>=0;--i){
        prtinf("%s\n",a[i]);
    }

    for(int i = 0;i<count;++i){
        free(a[i]);
    }
    free(a);
}