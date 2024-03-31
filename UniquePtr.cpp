#include <iostream>
#include <memory>

using namespace std;

class Resource {

    public:
    Resource() { cout << "Resource is created" ; }

    ~Resource() { cout << "Resource is destroyed" ;}

};

template<typename T>
class UniquePtr {
    private:
    T *ptr_ ;
    public:

    UniquePtr() : ptr_(nullptr){}

    UniquePtr(T * ptr = nullptr) : ptr_(ptr){
        cout << "custom unique ptr is constructed" << endl ;
    }

    ~UniquePtr() {
        cout << "custom unique ptr is destroyed" << endl;
        delete ptr_;
    }

    UniquePtr(const UniquePtr & other) = delete;
    UniquePtr & operator=(const UniquePtr & other) = delete;

    UniquePtr(UniquePtr && other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    UniquePtr & operator=(UniquePtr && other) {
        if (this != &other){
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }

        return *this;
    }

    T& operator*() {
        return *ptr_;
    }

    T* operator->(){
        return ptr_;
    }

    T* get() {
        return ptr_;
    }


};


int main(){
    
    //unique_ptr<Resource> up_r = make_unique<Resource>();
    //Resource * r1 = new Resource;

    UniquePtr<int> custom_ptr(new int(42));
    cout << *custom_ptr  << endl;

    UniquePtr<int> custome_ptr2 = move(custom_ptr);
    cout << *custome_ptr2 << endl;

    

}
