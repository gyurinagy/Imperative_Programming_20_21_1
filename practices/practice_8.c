#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int drawTable(int p[10][10] ){
    printf(" ");
    for(int i = 0;i<10;++i){
        printf(" %d",i);
    }
    printf("\n");
    char letter = 'A';
    for(int i= 0;i<10;++i){
        printf("%c",letter++);
        for(int j= 0;j<10;++j){
            printf(" %d",p[i][j]);
        }   
        printf("\n");
    }
}

int main(int argc, char** argv){

    if(atoi(argv[1]) <3  || atoi(argv[1])>30){
        printf("Hibás bemenet!\n");
        return -1;
    }
    //srand(time(0));

    //int** aknak;
    int mezok[10][10];
    for(int i= 0;i<10;++i) for(int j= 0;j<10;++j)
            mezok[i][j]=0;
           
        
    drawTable(mezok);


}