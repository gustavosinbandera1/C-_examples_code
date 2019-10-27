#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char name[20];
	int age;
};

int main()
{
	//structure variable declaratio with initialisation
	struct Person person={"Deniss Ritchie", 60};
	//declare character buffer (byte array)
	unsigned char *buffer=(char*)malloc(sizeof(person));
	int i;
	
	//copying....
	memcpy(buffer,(const unsigned char*)&person,sizeof(person));
	
	//printing..
	printf("Copied byte array is:\n");
	for(i=0;i<sizeof(person);i++)
		printf("%02X ",buffer[i]);
	printf("\n");
	
	//freeing memory..
	free(buffer);
	return 0;
}

/*
Copied byte array is:
44 65 6E 69 73 73 20 52 69 74 63 68 69 65 00 00 00 00 00 00 3C 00 00 00

name has 20 bytes and here is the value from buffer
44 65 6E 69 73 73 20 52 69 74 63 68 69 65 00 00 00 00 00 00
 
age has 4 bytes and here is the value from buffer
3C 00 00 00
 */