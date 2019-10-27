#include <stdio.h>
#include <iostream>
#include <cstring>


template <typename POD>
class SerializablePOD
{
public:

    static size_t serialize_size(POD str)
    {
        return sizeof(POD);
    }

    static char* serialize( char* target, POD value )
    {   //memcpy(data, &your_struct, sizeof(YourStruct))); // "Serialize"
        std::cout<<"el valor a serializar es: "<<value<<std::endl;
        //memcpy( target, &value, serialize_size(value) );
         //std::cout<<"valor serializado es  "<<sizeof((int*)target)<<std::endl;
        return (char*)memcpy( target, &value, serialize_size(value) );
        

        /*
        memcpy(data, &your_struct, sizeof(YourStruct))); // "Serialize"
memcpy(&your_struct, data, sizeof(YourStruct))); // "Deserialize"
        */
    } 

    static const char* deserialize( const char* source, POD& target )
    {
        std::cout<<"Vamos a deserializar"<<std::endl;
        memcpy( &target, source, serialize_size(target) );
        return source + serialize_size(target);
     
    }
};

 template<>
size_t SerializablePOD<char*>::serialize_size(char* str)
{
    return sizeof(size_t) + strlen(str);
}

template<>
const char* SerializablePOD<char*>::deserialize( const char* source, char*& target )
{
    size_t length;
    memcpy( &length, source, sizeof(size_t) );
    memcpy( &target, source + sizeof(size_t), length );
    return source + sizeof(size_t) + length;
}