/* #include <iostream>

class Base
{
    public:
    virtual void foo() = 0;
};

class Hija : public Base
{
};

int main()
{
    Hija h;

    return 0;
} */

/*
En este ejemplo vemos que el compilador nos indica un error. 
Es debido a que una de las peculiaridades de las clases abstractas o clases interfaces 
es que no se puede crear una instancia de ellas. 
Por lo tanto, al no estar definido foo, provoca el error.
*/
#include <iostream>
using namespace std;
class Animal
{
    public:
    virtual void comer() = 0;
};

class Gato : public Animal
{
    public:
    void comer() override
    {
        std::cout << "Soy un gato y estoy tomando leche"<<endl;
    }
};


class Perro : public Animal 
{
    public:
    void comer() override
    {
        std::cout << "soy un Perro y estoy comiendo concentrado"<<endl;
    }
};

int main()
{
    Gato miGato;
    Perro miPerro;
    miGato.comer();
    miPerro.comer();
    getchar();

    return 0;
}