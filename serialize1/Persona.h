#include <stdio.h>
#include <string.h>
#include "Serializable.h"
#include "SerializablePOD.h"



class Persona : public Serializable
{
public:
    Persona(/*char* _name = NULL,*/ int _age = 0, float _weight = 0, double _money = 0) : /*name(_name),*/ age(_age), weight(_weight), money(_money) 
    {}
    
    virtual size_t serialize_size() const
    {
        size_t size =   SerializablePOD<int>::serialize_size(age) +
                        SerializablePOD<float>::serialize_size(weight)  + 
                        SerializablePOD<double>::serialize_size(money);
        std::cout<<"size dentro de la funcion: "<<size<<std::endl;                
        return size;
    }

    virtual void serialize(char* dataOut) const
    {
        //dataOut = SerializablePOD<char*>::serialize(dataOut, name);
        dataOut = SerializablePOD<int>::serialize(dataOut, age);
        //std::cout<<"entero serializado: "<<dataOut<<std::endl;
        dataOut = SerializablePOD<float>::serialize(dataOut, weight);
        dataOut = SerializablePOD<double>::serialize(dataOut, money);
    }
     virtual void deserialize(const char* dataIn)
    {
         //dataIn = SerializablePOD<char*>::deserialize(dataIn, name);
        dataIn = SerializablePOD<int>::deserialize(dataIn, age);
        /* dataIn = SerializablePOD<float>::deserialize(dataIn, weight); 
        dataIn = SerializablePOD<double>::deserialize(dataIn, money); */
    } 

    int getAge()
    {
        return age;
    }
    float getWeight()
    {
        return weight;
    }
    double getMoney()
    {
        return money;
    }
private:
    //char *name;
    int   age;
    float weight;
    double money;
};