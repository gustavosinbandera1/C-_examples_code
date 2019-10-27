#include <iostream>
int compare(int a, int b) {
    if(a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}
int absolute_compare(int a, int b) {
    if(abs(a) > abs(b)) return 1;
    else if(abs(a) < abs(b)) return -1;
    else return 0;
}

void BubbleSort(int *A, int n, int (*compare)(int, int)) {
    int i,j,temp;
    for(i = 0; i<n; i++) {
        for(j = 0; j<n-1; j++) {
            //if(A[j] > A[j+1]) { //compare A[j] with A[j+1] and swap if needed
            if(compare(A[j],A[j+1]) > 0) {  
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

}

int main() {
    int i,A[] = {3,2,1,5,6,4};  //sort in increasing order
    int B[] = {-31,22,-1,50,-6,4};  //sort in increasing order
    BubbleSort(A,6,compare);
    BubbleSort(B,6,absolute_compare);
    for(i = 0; i<6; i++){
        std::cout<<A[i]<<std::endl;
    }

    for(i = 0; i<6; i++){
        std::cout<<B[i]<<std::endl;
    }
    return 0;
}