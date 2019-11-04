#include <iostream>
#include <stdio.h>
#include <cstring>



#include<stdlib.h> 
  
// A structure of type student 
struct student 
{ 
     //cero size
    int stud_id; 
    int name_len; 
  
    // This is used to store size of flexible 
    // character array stud_name[] 
    int struct_size; 
  
    // Flexible Array Member(FAM) 
    // variable length array must be last 
    // member of structure 
    char stud_name[20];

}; 
  
// Memory allocation and initialisation of structure 
struct student *createStudent(struct student *s, int id, const char a[]) 
{ 
    // Allocating memory according to user provided 
    // array of characters 
    s = (student*)malloc( sizeof(*s) + sizeof(char) * strlen(a)); 
    s->name_len = strlen(a); 
    strcpy(s->stud_name, a); 
    s->stud_id = id; 
    
  
    // Assigning size according to size of stud_name 
    // which is a copy of user provided array a[]. 
    s->struct_size = (sizeof(*s) + sizeof(char) * strlen(s->stud_name)); 
    std::cout << "dir in function: " << s << std::endl;
    return s; 
} 
  
// Print student details 
void printStudent(struct student *s) 
{ 
    printf("Student_id : %d\n" "Stud_Name : %s\n" "Name_Length: %d\n" "Allocated_Struct_size: %d\n\n", 
           s->stud_id,        s->stud_name,         s->name_len,       s->struct_size); 
  
        std::cout <<"Dir S1: -->" << s<< "\n";
        std::cout <<"Dir stduName: -->" << &s->stud_name << "\n";
        std::cout <<"Dir studId: -->" << &s->stud_id << "\n";
        std::cout <<"Dir nameLen: -->" << &s->name_len << "\n";
        std::cout <<"Dir structSize: -->" << &s->struct_size << "\n";
    
    // Value of Allocated_Struct_size is in bytes here 
} 
  
// Driver Code 
int main() 
{ 
    struct student *s1 = createStudent(s1, 523, "Cherry-me gustas mucho"); 
    std::cout <<"Dir S1: -->" << s1<< "\n";
     std::cout <<"Dir stduName: -->" << &s1->stud_name << "\n";
    std::cout <<"Dir studId: -->" << &s1->stud_id << "\n";
    std::cout <<"Dir nameLen: -->" << &s1->name_len << "\n";
    std::cout <<"Dir structSize: -->" << &s1->struct_size << "\n";
   
    //struct student *s2 = createStudent(s2, 535, "Sanjayulsha-estas muy largo"); 
    struct student *s3 = new student; // even this is questionable. */

/*     std::cout <<"Dir S2: -->" << s2 << "\t";
    std::cout <<"Dir S3: -->" << s3 << "\t" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "size char: " << sizeof(char) << std::endl; */
    printStudent(s1); 
/*     printStudent(s2);  */
  
    // Size in struct student 
    printf("Size of Struct student: %lu\n", 
                    sizeof(struct student)); 
  
    // Size in struct pointer 
    printf("Size of Struct pointer S1: %lu\n", 
                              sizeof(s1));  
    // Size in struct pointer 
/*     printf("Size of Struct pointer S2: %lu\n", 
                              sizeof(s2));  */
  
    return 0; 
} 