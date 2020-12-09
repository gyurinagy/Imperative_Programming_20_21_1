#include "stdio.h"
#include "stdlib.h"
#include "parity.h"


int main(){

    ParityArray p_array;
    InitParityArray(&p_array,20);


    InsertIntoParityArray(&p_array,2);
    InsertIntoParityArray(&p_array,5);
    InsertIntoParityArray(&p_array,6);
    InsertIntoParityArray(&p_array,3);
    PrintParityArray(&p_array);
    InsertIntoParityArray(&p_array,4);
    PrintParityArray(&p_array);

    DisposeParityArray(&p_array);
}