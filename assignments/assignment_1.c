#include <stdio.h>

int main(){

int rows;
do{
	printf("Enter the height of the pyramids (1-25): ");
	scanf(	"%d",&rows);
}while(rows<1 || rows>25);

for(int i=1;i<=rows;++i){
	for(int j=1;j<=rows-i;++j) printf(" ");
	
	for(int h = 0;h<2;++h){
		for(int k=1;k<=i;++k) printf("*");
		
		if(h==0) printf("  ");	
	}
	printf("\n");
	}
}
