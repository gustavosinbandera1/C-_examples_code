//functions pointers and callbacks

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

int compare(const void* a, const void* b) {
    int A = *((int*)a); //typecasting to int and getting valeu
    int B = *((int*)b);
    return abs(A)-abs(B);
}

int main() {
    int i, A[] = {-31,22,-1,50,-6,4};
    qsort(A,6,sizeof(int),compare);
    for(int i = 0; i < 6; i++)
    std::cout<<"salida: "<<A[i]<<std::endl;
}