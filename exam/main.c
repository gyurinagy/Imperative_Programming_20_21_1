#include "reversing.h"

int main(int argc, char* argv[]){

    if(argc>1){
        for (int i = 1; i < argc; i++)
        {
            FILE* file;
            file=fopen(argv[i],"r");
            if(file==NULL){
                 perror("Hiba fajl megnyitasakor!\n");
            }else{
                reverse(file);
                fclose(file);
            }
        }
    }else{
        reverse(stdin);
    }

}

