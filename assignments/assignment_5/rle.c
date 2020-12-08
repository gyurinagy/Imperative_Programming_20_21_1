#include "rle.h"
#include "string.h"
#include "stdlib.h"


struct Encoded* encode(char *str){
    struct Encoded *tmp = malloc(sizeof(struct Encoded));
    if(tmp==NULL) exit(EXIT_FAILURE);

    int letters[255] = {0}; // the letters in ascii
    int wordcounter[255] = {0}; // how many are there from the given characters
    int lettercounter=0; // the length of the string
    for(unsigned i = 0;i<strlen(str);++i){
        int counter=1;
        while (i < strlen(str) - 1 && str[i] == str[i + 1]) {
            counter++;
            i++;
        }
        letters[lettercounter] = str[i]-97;
        wordcounter[lettercounter] = counter;
        lettercounter++;
    }

    tmp->_length=lettercounter;

    struct Pair *pairs = calloc(lettercounter,sizeof(struct Pair));
    if(pairs==NULL) exit(EXIT_FAILURE);
    for(int i = 0;i<lettercounter;++i){
        
        pairs[i]._c =letters[i]+97;
        pairs[i]._n = wordcounter[i];
    }
    tmp->_arr = pairs;
    
    return tmp;
}


char *decode(struct Encoded* enc){
    char* str = calloc(enc->_length,sizeof(char));

    int k = 0;
    for (unsigned i = 0;i<enc->_length;++i) {
        for (unsigned j = 0;j<enc->_arr[i]._n;++j) {
            str[k]=enc->_arr[i]._c;
            k++;
        }
    }
    str[k]='\0';
    
    return str;
}