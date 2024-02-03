
#include<iostream>
#include<memory>
#include"memory.h"

using namespace std;


class MyString{

    private:
    
    char * m_data ;
    unsigned int m_size;

    public:

    MyString(): m_data(nullptr) , m_size(0){}   // default constructor

    MyString(const char * data){                      // parametrized constructor
        
        cout << "invoking parametrized constructor" << endl;

        if (data != nullptr){
            m_size = strlen(data);
            m_data = new char[m_size];
            memcpy(m_data , data , m_size); 
        }

    }

    MyString( const MyString &other) {
        if (other.m_data){
            m_size = strlen(other.m_data);
            m_data = new char[m_size];
            memcpy(m_data , other.m_data , m_size);
        }
    }


    MyString& operator=(const MyString &other){

        if(this != &other){
            delete[] m_data ; 
            m_size = other.m_size;
            m_data =  new char[m_size];
            memcpy(m_data , other.m_data , m_size);
        }

        return *this;
    }



    ~MyString(){
        cout << "calling destructor" << endl;
        delete[] m_data;
    }

    friend ostream& operator<<(ostream & out , MyString & str);

    void PrintString(){
        for(int i = 0 ; i < m_size ; i++){
            cout << m_data[i];
        }
        cout << endl;
    }

};



ostream& operator<<(ostream & out , MyString & str){

    for (int i = 0 ; i < str.m_size ; i++)
        out << str.m_data[i];
    return out;

}




int main(){

    MyString str1;
    MyString str2("Abhinav");
    MyString str4("tiwari");

    cout << str1;
    cout << str2 << endl;

    // str1.PrintString();
    // str2.PrintString();

    MyString str3 = str2;
    // str3.PrintString();

    str3 = str4;
    // str3.PrintString();


}

