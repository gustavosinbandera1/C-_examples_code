#include <iostream>
#include <stdio.h>
#include <string.h>
int main() {

char *str;
int size = 4;
str = (char*)malloc(sizeof(char)*size);
//strlen(str);
std::cout<<"tamano: "<<strlen(str) <<std::endl:
*(str+0) = 'G';
*(str+1) = 'f';
*(str+2) = 'G';
*(str+3) = '\0';  
std::cout<<"Salida: "<<str<<std::endl;

return 0;
} 

  /*   #include <stdio.h>
    #include <string.h>
    int main()
    {
        char a[20]="Program";
        char b[20]={'P','r','o','g','r','a','m','\0'};
        printf("Length of string a = %ld \n",strlen(a));
        printf("Length of string b = %ld \n",strlen(b));
        return 0;
    } */