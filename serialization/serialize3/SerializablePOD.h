#include <stdio.h>
#include <iostream>
#include <cstring>


template <typename POD>
class SerializablePOD
{
public:

    static size_t serialize_size(POD str)
    {
        return sizeof(str);
    }

    static char* serialize( char* target, POD value )
    {  
        memcpy( target, &value, serialize_size(value) );
        std::cout << "verificado" << serialize_size(value) << std::endl;
        return target + sizeof(value); //move the pointer to the next addres
    } 

    static const char* deserialize( const char* source, POD& target )
    {
        std::cout << "Vamos a deserializar" << std::endl;
        memcpy( &target, source, serialize_size(target) );
        return source +sizeof(target);
    }
};

template<>
size_t SerializablePOD<char*>::serialize_size(char* str)
{
    std::cout<<"el TAMANO del char* "<<sizeof(size_t) + strlen(str)<<std::endl;
    return sizeof(size_t) + strlen(str);
}

template<>
const char* SerializablePOD<char*>::deserialize( const char* source, char*& target )
{
    size_t length ;
    char* test;
    std::cout <<"Vamos a deserializar char* " << std::endl;
    std::cout <<":----------address of char fiel in structure------------------------------->"<< static_cast<const void*>(&target)<<std::endl;
    memcpy( &length, source, sizeof(size_t));
    std::cout << "el length of string.."<< (size_t)length << std::endl;
    source = source +sizeof(size_t);
    //target = (char*)malloc(sizeof(char)*length); //error
    memcpy( target, source, length);
    std::cout << "salida: " << std::string(source,length) << std::endl;
    std::cout << "dato en el field despues de deserializar: : " << target << std::endl;
    std::cout <<":----------address->"<< static_cast<const void*>(target)<<std::endl;

    return source + length;  

}

template<>
char* SerializablePOD<char*>::serialize( char* target, char* value )
{  
    
    size_t l = strlen(value);
    std::cout << ": dir buffer ---------->" << static_cast<const void*> (&target) << std::endl;
    std::cout << ": dir inside pointer to put data ---------->" << static_cast<const void*> (value) << std::endl;
    std::cout << "vamos a serializar char*->" << l << std::endl;
    memcpy( target, &l , sizeof(size_t) );
    target = target + sizeof(size_t);
    memcpy( target, value, strlen(value) );
    std::cout << target << std::endl;
    return target + l;

} 