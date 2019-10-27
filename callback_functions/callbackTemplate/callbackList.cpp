#include <iostream>
#include <string>
#include <vector>

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




class AClass
{
public:

   AClass(unsigned int id) : id_(id) {}

   bool AMethod(const std::string& str)
   {
      std::cout << "AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

   unsigned int id_;
};


typedef SingularCallBack <AClass, bool, const std::string&> ACallBack;


int main()
{
   std::vector<ACallBack> callback_list;

   AClass a1(1);
   AClass a2(2);
   AClass a3(3);

   callback_list.push_back(ACallBack(&a1, &AClass::AMethod));
   callback_list.push_back(ACallBack(&a2, &AClass::AMethod));
   callback_list.push_back(ACallBack(&a3, &AClass::AMethod));

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i]("abc");
   }

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i].execute("abc");
   }

   return 0;
}
