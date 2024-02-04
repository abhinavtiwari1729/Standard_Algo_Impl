#include<iostream>

using namespace std;


template<typename T>
class MySharedPointer{

private:
    T* m_data;
    int* ref_count;

public:

    MySharedPointer() : m_data(nullptr) , ref_count(nullptr){}
    

    MySharedPointer(T * data) : m_data(data) , ref_count(new int(1)){}

    ~MySharedPointer(){
        release();
    }
    MySharedPointer(const MySharedPointer& other){      
            m_data = other.m_data;
            ref_count = other.ref_count;
            if(ref_count)
                (*ref_count)++;
    }
    MySharedPointer& operator=(const MySharedPointer& other){

        if(this != &other){
            release();
            m_data = other.m_data;
            ref_count = other.ref_count;
            if(ref_count)    
                (*ref_count)++;            
        }
        return *this;
    }



    MySharedPointer(MySharedPointer && other){
        if(other.ref_count){
            m_data = other.m_data;
            ref_count = other.ref_count;
            other.m_data = nullptr;
            other.ref_count = nullptr;
        }

    }


    MySharedPointer& operator=(MySharedPointer && other){
        if (this != &other){
            if(other.ref_count){
                release();
                m_data = other.m_data;
                ref_count = other.ref_count;
                other.m_data = nullptr;
                other.ref_count = nullptr;
            }
        }
        return *this ;
    }



    void release(){
        if(ref_count){
            (*ref_count)--;
            if(*ref_count == 0){
                delete m_data;
                delete ref_count;
                m_data = nullptr;
                ref_count = nullptr;
            }

        }
    }
    int GetRefCount(){
        if(ref_count)
            return *ref_count;

        return 0;       
    }
    T* operator->(){
        return m_data;
    }
    T& operator*(){
        return *m_data;
    }

};


int main(){

    MySharedPointer<int> p1(new int(10));
    MySharedPointer<int> p2 = p1;

    cout << *p2 << " " <<p2.GetRefCount() << endl;
    cout << *p1 << " " <<p1.GetRefCount() << endl;

}