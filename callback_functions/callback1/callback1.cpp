#include <stdio.h>
#include <iostream>


void A() {
    std::cout<<"I am function A"<<std::endl;
}


void B(void (*ptr)()) {
    (*ptr) ();  //callback to A
}

int main() {
    void (*ptr)() = &A;
    //calling function B and passing
    // address of the function A as argument
    B(ptr);
    return 0;

}
