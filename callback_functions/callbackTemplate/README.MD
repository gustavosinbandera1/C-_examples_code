# USAGE OF THE TEMPLATE

 Usage of the template is very simple. The template itself can be instantiated as an object pointer or just as a simple class. 
 
 When being used as an object pointer, C++ has another painful limitation and that is that the operator() can not be invoked without dereferencing the object pointer, a quick and dirty solution was to place an execute() method within the template, which calls the operator() from within the template itself. Other than that little problem, instantiating the SingularCallBack as an object pointer will allow you to have a vector of callbacks, or any other kind of grouping which is highly desirable in event driven programming.

Lets assume the following 2 classes exist, and that we want to have methodB() as our callback method. From the code we can see that when methodB() is invoked with the paramter of class A, methodB() will then invoke the method output() in class A. The proof that the callback really worked is if we see the line "I am class A :D" in the stdout. 