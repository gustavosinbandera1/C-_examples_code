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
        //I suppouse this is my callback function
   bool methodB(A a)
   {
      a.output();
      return true;
   }
//other callback function
   int methodB_B(A a)
   {
      std::cout << "other test method" << std::endl;
      return 5;
   }
};



int main() {
    A a;
    B b;

    SingularCallBack<B,bool,A>* cb;
    cb = new SingularCallBack<B,bool,A>(&b,&B::methodB);

    if(cb->execute(a))
    {
    std::cout << "CallBack Fired Successfully!" << std::endl;
    }
    else
    {
    std::cout << "CallBack Fired Unsuccessfully!" << std::endl;
    }
    return 0;
}