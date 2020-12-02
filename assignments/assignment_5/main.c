#include "stdio.h"
#include "stdlib.h"
#include "rle.h"

int main(){


    char inputStr[255];
    scanf("%s",inputStr);
    int i = 0;
    for (i = 0; inputStr[i]!='\0'; ++i);
    for(int j = 0;j<i;++j){
        if(inputStr[j]<97 || inputStr[j]>122){
            printf("Hibas bemenet!\n");
            return EXIT_FAILURE;
        }
    }
    
    char* strPointer = calloc(i, sizeof(char));
    if(strPointer==NULL) exit(EXIT_FAILURE);
    strPointer = inputStr;   
      
    struct Encoded * en = encode(strPointer);

    for(unsigned i = 0;i<en->_length;++i)
        printf("%d%c",en->_arr[i]._n,en->_arr[i]._c);
    printf(" -> "); printf("%s\n",decode(en));

    free(strPointer);
    free(en->_arr);
    free(en);
    
    return EXIT_SUCCESS;
}