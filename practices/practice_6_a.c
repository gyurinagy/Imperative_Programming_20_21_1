#include <stdio.h>

int main(int argc, char ** argv){
    // argc -> hány argumentumot kapott a program
    // argv argumentumok tömbje 
    int result =1,i;
    // sscanf char* kér, megadjuk hogy mit szeretnénk és mibe
    //sscanf(argv[0],"%d",&i);
    //atoi(argv[0]);
    for(int i = 0; i<argc;++i){
        result *= atoi(argv[i]); 
    }
}