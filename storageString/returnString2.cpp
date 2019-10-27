#include <iostream>

char *getString() 
{ 
  int size = 4; 
  char *str = (char *)malloc(sizeof(char)*size); /*Stored in heap segment*/
  *(str+0) = 'G';  
  *(str+1) = 'f';   
  *(str+2) = 'G'; 
  *(str+3) = '\0';   
    
  /* No problem: string remains at str after getString() returns */    
  return str;   
}      
int main() 
{ 
  printf("%s", getString());   
  getchar(); 
  return 0; 
} 
