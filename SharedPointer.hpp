#include "SharedPointer.h"

template <typename T> 
SharedPointer<T>::SharedPointer(){
    pData = nullptr;
    reference = new Counter();
    reference->AddRef();
}
template <typename T> 
SharedPointer<T>::SharedPointer(T* pValue) {
    pData = pValue;
    reference = new Counter();
    reference->AddRef();
}
template <typename T> 
SharedPointer<T>::SharedPointer(const SharedPointer<T>& SharedPtr){
    pData = SharedPtr.pData;
    reference = SharedPtr.reference;
    reference->AddRef();
}
template <typename T> 
SharedPointer<T>::~SharedPointer() {
    if(reference->Release() == 0) {
        delete pData;
        delete reference;
    }
}
template <typename T> 
T& SharedPointer<T>:: operator* () {
    return *pData;
}
template <typename T> 
T* SharedPointer<T>:: operator-> () {
    return pData;
}
template <typename T> 
SharedPointer<T>& SharedPointer<T>::operator = (const SharedPointer<T>& SharedPtr)
{
    if (this != &SharedPtr) 
    {
        if(reference->Release() == 0)
        {
            delete pData;
            delete reference;
        }
        pData = SharedPtr.pData;
        reference = SharedPtr.reference;
        reference->AddRef();
    }
    return *this;
}
template <typename T>
template <typename U> 
bool SharedPointer<T>::operator == (const SharedPointer<U>& SharedPtr){
    return pData == SharedPtr.pData;
}
template <typename T>
template <typename U> 
bool SharedPointer<T>::operator != (const SharedPointer<U>& SharedPtr){
    return pData != SharedPtr.pData;
}

template <typename T> 
bool operator == (const SharedPointer<T>& SharedPtr1, const SharedPointer<T>& SharedPtr2){
    return SharedPtr1.pData != SharedPtr2.pData;
}
template <typename T> 
bool operator != (const SharedPointer<T>& SharedPtr1, const SharedPointer<T>& SharedPtr2){
    return SharedPtr1.pData != SharedPtr2.pData;
}