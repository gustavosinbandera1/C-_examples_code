# CALLBACK FUNCTIONS

Callbacks are tremendously useful in object-oriented design when one needs to decouple two classes but let them be connected via a single function call. Examples abound and at some point I'll expand. For now, this is a place for me to keep my experiments with various approaches to implementing callbacks in C++.

## Ideal Solution

Wouldn't it be nice if C++ supported callbacks directly? Let's say we have a timer class that takes a callback which it will call periodically. It would be great to be able to do this:

```cpp 
Timer t;  // caller
MyClass myObject;  // callee

t.connect(myObject.foo);  // callback
t.start(1);  // 1 second period
```

Every second, the Timer object t would call the connected callback function myObject.foo().

Unfortunately, C++ does not offer anything like this. myObject.foo is a combination of the object pointer &myObject and the member function pointer foo. C++ does not have a pointer type that combines these two pointers.