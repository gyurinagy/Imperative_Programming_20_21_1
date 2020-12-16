#include <string.h>
#include <stdlib.h>
#include "reversing.h"


char** read(FILE* fp,char** lines, int* lSize){
    char c;
    int strsize=0;
    char tmpline[BUFSIZE];
    int arrSize=INITCAP;

    do{
        c = fgetc(fp);
        
        if(c=='\n' || c==EOF ){
            

            // méret túllépés esetén realloc
            if((*lSize)%INITCAP==0 && (*lSize)>INITCAP-1){

                char** tmp = realloc(lines,(arrSize*2)*sizeof(char*));
                if(tmp!=NULL) lines = tmp;

                // for(int i = (*lSize);i<arrSize*2;i++){
                //     lines[i] = malloc(BUFSIZE*sizeof(char));
                //     if(lines[i]==NULL) perror("Hiba!");
                // }
                arrSize*=2;
            }


            // .trim()
            while(tmpline[strsize-1]==' ' || tmpline[strsize-1]=='\r'){
                    tmpline[strsize-1]=0;
                    strsize--;
            }

            // csak akkor malloc-olok területet a string-nek, ha az biztosan bekerul a tombbe
            // 8 elem tullepese eseten a reverse fuggveny nem tudja mekkora a lines merete, csak hogy hány string van benne (lSize)
            // ezzel elkerülöm a terulet előre foglalasat, amit vegul nem tudnek felszabaditani, mert csak lSize-t ismerem 
            lines[*lSize] = malloc(BUFSIZE*sizeof(char));
            if(lines[*lSize]==NULL) perror("Hiba!");

            strcpy(lines[*lSize],tmpline);
            (*lSize)++;

            // ideiglenes sor és méretének nullázása
            for(int i = 0;i<strsize;++i){
                tmpline[i]=0;
            }
            strsize=0;

        }else{
            tmpline[strsize]=c;
            strsize++;
        }

    }while(c != EOF);
 
    return lines;
}

void write(char** lines,int lSize){

    for(int i = lSize-1;i>=0;--i){

        printf("%d ",i+1);
        for(int j = strlen(lines[i]);j>=0;--j)
            printf("%c",lines[i][j]);
        
        printf("\n");
    }
}

void reverse(FILE* fp){
    char** lines;
    int lSize=0;

    lines=malloc(INITCAP*sizeof(char*));
    if(lines==NULL) perror("Hiba!");
    // for(int i = 0;i<INITCAP;++i){
    //     lines[i] = malloc(BUFSIZE*sizeof(char));
    //     if(lines[i]==NULL) perror("Hiba!");
    // }

    lines = read(fp,lines,&lSize);
    write(lines,lSize);

    for(int i =0;i<lSize;++i)free(lines[i]);
    free(lines);
}
