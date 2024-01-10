#include <iostream>
#include <memory>
using namespace std;


template<typename T>
class MyShared_Ptr{

    private:
    
    T * ptr_ = nullptr;
    int * ref_count = nullptr;

    public:

    MyShared_Ptr(): ptr_(nullptr) , ref_count(nullptr){}

    MyShared_Ptr(T * ptr) : ptr_(ptr) {
        if (ptr != nullptr) {
            ref_count = new int(1);
        }
    }
    // copy semantics 
    MyShared_Ptr(const MyShared_Ptr &other) {
        ptr_ = other.ptr_;
        ref_count = other.ref_count;
        if (ref_count != nullptr)
            *ref_count++;
    }

    MyShared_Ptr & operator= (const MyShared_Ptr &other) {
        if (this != &other) {
            release();
            ptr_ = other.ptr_;
            ref_count = other.ref_count;
            if (ref_count != nullptr)
                *ref_count++;

        }

        return *this;
    }


    // move semantics

    MyShared_Ptr(MyShared_Ptr &&other) {
        
        ptr_ = other.ptr_;
        ref_count = other.ref_count;

        other.ptr_ = nullptr;
        other.ref_count = nullptr;
    }


    MyShared_Ptr& operator=(MyShared_Ptr &&other) {

        if (this != &other) {
            release();
            ptr_ = other.ptr_;
            ref_count = other.ref_count;
            other.ptr_ = nullptr;
            other.ref_count = nullptr;
        }

        return *this;
    }



    ~MyShared_Ptr() {
        release();
    }


    void release() {
        if (ref_count != nullptr) {

            *ref_count--;
            if (*ref_count == 0) {

                delete ptr_;
                delete ref_count;
                ptr_ = nullptr;
                ref_count = nullptr;

            }
        }
    }



};
