#include <stdio.h>

int f(){
    printf("f");
    return 0;

}

int S(){
    printf("S");
    return 1;
}

int main() {
   if(f(),S()){
       printf("h");
   }
   return 0;
}