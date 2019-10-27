#include <iostream>
using namespace std;

template <class tipo> 
tipo mayor(tipo dato1, tipo dato2){
    return (dato1 > dato2 ? dato1 : dato2);
}

int main(){
    int a = 1, b = 2, n; 
    float c = 1.0, d = 0.5, m; 
    
    n = mayor <int> (a,b); // Usando enteros
    m = mayor <float>(c,d);        // Usando reales
    
    cout << "Entero mayor: " << n << endl;
    cout << "Real mayor: " << m << endl;
    
    return 0; 
}

//g++ -o template templateMayor.cpp 