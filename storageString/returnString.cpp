#include <iostream>

char *getString() 
{ 
  char *str = "GfG"; /* Stored in read only part of shared segment */
  
  /* No problem: remains at address str after getString() returns*/
  return str;   
}      
  
int main() 
{ 
  printf("%s\n", getString());  
  std::cout<<"Salida"<< getString()<<std::endl;
  getchar(); 
  return 0; 
} 
