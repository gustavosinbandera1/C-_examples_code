#include <iostream>  
using namespace std;  
  
/*template <class identificador> definición_de_función;
template <typename identificador> definición_de_función;*/
template < class T >  
T sum(T a[],int sz)  
{  
    int i;  
    T ans=0;  
    for(i=0;i<sz;i++)  
        ans += a[i];  
    return ans;  
}  
  
int main()  
{  
   // Sample use of template function  
   int a[4] = {1,2,3,4};  
   float b[5] = {1.2,0.8,1.2,10.1,10.2};  
  
   cout << "Integer array sum : " << sum<int>(a,4) << "\n";  
   cout << "Float array sum : " << sum<float>(b,5) << "\n";  
  
    return 0;  
}