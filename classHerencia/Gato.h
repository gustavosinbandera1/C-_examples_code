#include <iostream>
#include "Animal.h"

class Gato : public Animal
{
    public:
    virtual int comer() override
    {
        std::cout << "Soy un gato y estoy tomando leche"<<std::endl;
    return 2;
    }
};