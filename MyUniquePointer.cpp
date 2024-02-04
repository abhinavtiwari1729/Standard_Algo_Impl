#include<iostream>

using namespace std;

template<typename T>
class MyUniquePointer {

private:
    T* m_data;

public:

MyUniquePointer(): m_data(nullptr){   // default constructor

}


MyUniquePointer(T* data) : m_data(data){}

~MyUniquePointer(){    // destructor
    delete m_data;
}


MyUniquePointer(const MyUniquePointer & other) = delete ;  // copy constructor

MyUniquePointer& operator=(const MyUniquePointer & other) = delete; // copy assignment operator


MyUniquePointer(MyUniquePointer && other){
    
    m_data = other.m_data;
    other.m_data = nullptr; 
}


MyUniquePointer& operator=(MyUniquePointer && other){

    if(this != &other){
        delete m_data;
        m_data = other.m_data;
        other.m_data = nullptr;
    }
    return *this;
}

T* operator->(){
    return m_data;
}

T& operator*(){
    return *m_data;
}

};






int main(){

    MyUniquePointer<int> p1(new int(10));

    cout << *p1 << endl;

    MyUniquePointer<int> p2 = std::move(p1);
    cout << *p2 << endl;

    p1 = std::move(p2) ;
    cout << *p1 << endl;

}