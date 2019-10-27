#include <iostream>


int main() {

char* str ;   //but the pointer is stored in read/write memory
str = "GFG"; //gfg is stored in a shared read only location, we cannot edit the content
std::cout<<"salida: "<<str;
getchar();

    return 0;
}