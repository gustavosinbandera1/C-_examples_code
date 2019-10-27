#include <iostream>

template <class Class, typename ReturnType, typename Parameter>
class SingularCallBack
{
public:

   typedef ReturnType (Class::*Method)(Parameter);

   SingularCallBack(Class* class_instance, Method method) : class_instance_(class_instance), method_(method) { }

   ReturnType operator()(Parameter parameter)
   {
      return (class_instance_->*method_)(parameter);
   }

   ReturnType execute(Parameter parameter)
   {
      return operator()(parameter);
   }

private:

   Class* class_instance_;
   Method method_;
};



class A
{
public:

   void output()
   {
      std::cout << "I am class A :D" << std::endl;
   }
};

class B
{
public:

   bool methodB(A a)
   {
      a.output();
      return true;
   }

   int methodB_B(A a)
   {
      std::cout << "other test method" << std::endl;
      return 5;
   }
};





int main() {

//dereference the object pointer and run callback method     () operator)
A a;
B b;

SingularCallBack<B,bool,A>* cb1;
cb1 = new SingularCallBack<B,bool,A>(&b,&B::methodB);

SingularCallBack<B,int,A>* cb2;
cb2 = new SingularCallBack<B,int,A>(&b,&B::methodB_B);



if((*cb1)(a)) {
    std::cout << "Callback fired Successfully" << std::endl;
} else {
    std::cout << "Callback Fired Unsuccessfully"<< std::endl;
}

    return 0;
}