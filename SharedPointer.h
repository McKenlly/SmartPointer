#ifndef SHARED_POINTER
#define SHARED_POINTER

#include "Counter.h"

template <typename T> 
class SharedPointer
{
private:
    T* pData;  
    Counter* reference;
public:
    explicit SharedPointer();
    SharedPointer(T*);

    SharedPointer(const SharedPointer<T>&);
    ~SharedPointer();

    T& operator* ();
    T* operator-> ();
    //Виклидатор неоднозначностей.
    template <typename U> 
    bool operator == (const SharedPointer<U>&);
    template <typename U> 
    bool operator != (const SharedPointer<U>&);


    template <typename A> 
    friend bool operator == (const SharedPointer<A>&, const SharedPointer<A>&);
    template <typename A> 
    friend bool operator != (const SharedPointer<A>&, const SharedPointer<A>&);
    SharedPointer<T>& operator = (const SharedPointer<T>&);
};
#include "SharedPointer.hpp"
#endif