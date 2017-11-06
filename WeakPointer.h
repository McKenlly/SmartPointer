#ifndef WEAK_POINTER
#define WEAK_POINTER

#include "Counter.h"

template<class T> 
class WeakPointer
{
public:
  WeakPointer();
  template<class Y> 
  WeakPointer(shared_ptr<Y> const& r);
  
  WeakPointer(WeakPointer<T> const& r);
  template<class Y> WeakPointer(WeakPointer<Y> const& r);

  ~WeakPointer();

  WeakPointer<T>& operator = (WeakPointer<T> const& r);
  WeakPointer& operator=(WeakPointer<T> const& r);
  // modifiersvoid swap(WeakPointer& r);
  void reset();
  // observerslong use_count() const;
  bool expired() const;
  shared_ptr<T> lock() const;
};

#endif