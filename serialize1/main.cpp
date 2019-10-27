#include <iostream>
#include "Persona.h"



int main() {


int size = 11; 
  char *str ;
  str =  (char *)malloc(sizeof(char)*size); /*Stored in heap segment*/
  *(str+0) = 'G';  
  *(str+1) = 'f';   
  *(str+2) = 'G'; 
  *(str+3) = 'A';
   *(str+4) = 'G';
  *(str+5) = 'G';  
  *(str+6) = 'f';   
  *(str+7) = 'G'; 
  *(str+8) = 'G';
  *(str+9) = 'G';
  *(str+10) = '\0';  


Persona miPersona(32,45.65,5400);
size_t length =  miPersona.serialize_size();
std::cout<<"el length es : "<<length<<std::endl;
std::cout<<"el tamano de la estructura es "<<sizeof(miPersona)<<std::endl;



char* buffer;
buffer  = (char*)malloc(sizeof(char)*length);
//std::cout<<"el tamano del buffer es :"<<strlen(buffer)<<std::endl;

//buffer = str;
//std::cout<<"el buffer con data en main :"<<buffer<<std::endl;
miPersona.serialize(buffer);
std::cout<<"el buffer con data en main :"<<strlen(buffer)<<std::endl;

size_t buffer_size = sizeof(int) + sizeof(float) + sizeof(double);
char* buf = new char[buffer_size];
*(int*)buf = sizeof(int);
memcpy(buf,buffer,sizeof(int));
std::cout<<"salida"<<buf<<std::endl;
//std::cout<<"lo que hay"<<p<<std::endl;
/*  
//std::cout<<"esto es : "<<sizeof(buffer)<<std::endl;
miPersona.deserialize(buffer);
std::cout<<"salida final: "<<buffer<<std::endl;  */

free(buffer);

    return 0;
}