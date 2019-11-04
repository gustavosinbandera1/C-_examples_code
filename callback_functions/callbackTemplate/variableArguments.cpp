template <class Class, typename ReturnType, typename Parameter1 = void,
                                            typename Parameter2 = void,
                                            typename Parameter3 = void,
                                            typename Parameter4 = void>
class CallBack
{
public:

   typedef ReturnType (Class::*Method)(Parameter1, Parameter2, Parameter3, Parameter4);

   CallBack(Class* class_instance, Method method) : class_instance_(class_instance),method_(method) { }

   ReturnType operator()(Parameter1 p1, Parameter2 p2, Parameter3 p3, Parameter4 p4)
   {
      return (class_instance_->*method_)(p1, p2, p3, p4);
   }

   ReturnType execute(Parameter1 p1, Parameter2 p2, Parameter3 p3, Parameter4 p4)
   {
      return operator()(p1, p2, p3, p4);
   }

private:

   Class* class_instance_;
   Method method_;
};



template <class Class, typename ReturnType, typename Parameter1,
                                            typename Parameter2,
                                            typename Parameter3>

class CallBack <Class, ReturnType, Parameter1, Parameter2, Parameter3>
{
public:

   typedef ReturnType (Class::*Method)(Parameter1, Parameter2, Parameter3);
   
   CallBack(Class* class_instance, Method method) : class_instance_(class_instance), method_(method) { }

   ReturnType operator()(Parameter1 p1, Parameter2 p2, Parameter3 p3)
   {
      return (class_instance_->*method_)(p1, p2, p3);
   }

   ReturnType execute(Parameter1 p1, Parameter2 p2, Parameter3 p3)
   {
      return operator()(p1, p2, p3);
   }

private:

   Class* class_instance_;
   Method method_;
};


template <class Class, typename ReturnType, typename Parameter1, typename Parameter2>
class CallBack <Class, ReturnType, Parameter1, Parameter2>
{
public:

   typedef ReturnType (Class::*Method)(Parameter1,Parameter2);

   CallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()(Parameter1 p1, Parameter2 p2)
   {
      return (class_instance_->*method_)(p1, p2);
   }

   ReturnType execute(Parameter1 p1, Parameter2 p2)
   {
      return operator()(p1, p2);
   }

private:

   Class* class_instance_;
   Method method_;
};



template <class Class, typename ReturnType, typename Parameter>
class CallBack <Class, ReturnType, Parameter>
{
public:

   typedef ReturnType (Class::*Method)(Parameter);

   CallBack(Class* class_instance, Method method) : class_instance_(class_instance), method_(method) { }

   ReturnType operator()(Parameter p1)
   {
      return (class_instance_->*method_)(p1);
   }

   ReturnType execute(Parameter p1)
   {
      return operator()(p1);
   }

private:

   Class*  class_instance;
   Method  method;
};



template <class Class, typename ReturnType>
class CallBack <Class, ReturnType>
{
public:

   typedef ReturnType (Class::*Method)(void);

   CallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()()
   {
      return (class_instance_->*method_)();
   }

   ReturnType execute()
   {
      return operator()();
   }

private:

   Class* class_instance_;
   Method method_;
};




