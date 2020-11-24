#include <stdio.h>

int maxElement(int a[], int size){
int maxE =a[0];
for(int i = 0;i<size;++i){
	if(a[i]>maxE) maxE=a[i];
}
return maxE;
}
int secondMinElement(int a[], int size){
int minE =a[0];
int minE2 = a[0];
for(int i = 1;i<size;++i){
	if(a[i]<minE){
		minE2 = minE;
		minE=a[i];
	}
}
return minE2;
}

int main(){

int array[10] = {55,234,435,345,25,5,23,54,53,10};
char asd[] = "ez egy string.";
printf("%ld\n", (sizeof(asd)/sizeof(char)));
int count = 0;
while(asd[++count]);
printf("%d\n",count);


//printf("%d\n",secondMinElement(array,10));
}
