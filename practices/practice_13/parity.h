#ifndef PARITY_H
#define PARITY_H

#define MAX_ARRAY_SIZE 20

struct ParityArray{
    int* array;
    int even_idx, odd_idx,max_size;
}typedef ParityArray;

int InsertIntoParityArray(ParityArray*,int);

void PrintParityArray(ParityArray*);

int InitParityArray(ParityArray *,unsigned);

void DisposeParityArray(ParityArray*);

#endif 