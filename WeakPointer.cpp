#include "iostream"
#include<stdlib.h>
class Counter
{
    private:
    int count;
    public:
        Counter{count = 0;}
        void AddRef() {count++;}
        int Release() {return --count;}
        virtual ~Counter(){}
};

template < typename T > class SmartPointer
{
private:
    T* pData;       // pointer
    Counter* reference; // Reference count

public:
    SmartPointer(){
        pData = nullptr;
        reference = new Counter();
        reference->AddRef();
    }
    SmartPointer(T* pValue) {
        pData = pValue;
        reference = new Counter();
        reference->AddRef();
    }

    SmartPointer(const SmartPointer<T>& SmartPointer){
        pData = SmartPointer.pData;
        reference = SmartPointer.reference;
        reference->AddRef();
    }
    ~SmartPointer() {
        if(reference->Release() == 0) {
            delete pData;
            delete reference;
        }
    }

    T& operator* () {
        return *pData;
    }

    T* operator-> () {
        return pData;
    }
    
    SmartPointer<T>& operator = (const SmartPointer<T>& SmartPointer)
    {
        if (this != &SmartPointer) 
        {
            if(reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }
            pData = SmartPointer.pData;
            reference = SmartPointer.reference;
            reference->AddRef();
        }
        return *this;
    }
};


int main()
{

    SmartPointer<int> *p = new SmartPointer<int>(new int(114));
    std::cout << **p << std::endl;
    SmartPointer<int> f = *p;
    delete p;
    std::cout << *f << std::endl;
    return 0;
}