#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int matrix1[2][3];
int matrix2[3][2];

void multiply_matrices( int m1[2][3], int m2[3][2]){
    int result[2][2];
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            result[i][j]=0;
            for (int k = 0; k < 3; ++k){
                result[i][j]+=m1[i][k]*m2[k][j];
            }
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    srand(time(0));
    for(int i = 0;i<2;++i){
        for(int j = 0;j<3;++j){
            matrix1[i][j] = rand()%10;
            matrix1[j][i] = rand()%10;
        }   
    }
    for(int i = 0;i<2;++i){
        for(int j = 0;j<3;++j){
            printf("%d ",matrix1[i][j]);
        }   
        printf("\n");
    }
    for(int i = 0;i<3;++i){
        for(int j = 0;j<2;++j){
            printf("%d ",matrix2[i][j]);
        }   
        printf("\n");
    }
      printf("\n");
      multiply_matrices(matrix1,matrix2);
}