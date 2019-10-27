#include <iostream>
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




class BaseClass
{
public:

   virtual ~BaseClass(){}

   virtual bool DerivedMethod(const std::string& str){ return true; }

};

class AClass : public BaseClass
{
public:

   AClass(unsigned int id) : id_(id)
   {}

   bool AMethod(const std::string& str)
   {
      std::cout << "AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

   bool DerivedMethod(const std::string& str)
   {
      std::cout << "Derived Method AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

   unsigned int id_;
};

class BClass : public BaseClass
{
public:

   BClass(unsigned int id) : id_(id) {}

   bool BMethod(const std::string& str)
   {
      std::cout << "BClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

   bool DerivedMethod(const std::string& str)
   {
      std::cout << "Derived Method BClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

 unsigned int id_;
};


typedef SingularCallBack <BaseClass, bool, const std::string&> BaseCallBack;

int main()
{
   std::vector<BaseCallBack> callback_list;

   AClass a(1);
   BClass b(2);

   callback_list.push_back(BaseCallBack(&a, &BaseClass::DerivedMethod));
   callback_list.push_back(BaseCallBack(&b, &BaseClass::DerivedMethod));

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