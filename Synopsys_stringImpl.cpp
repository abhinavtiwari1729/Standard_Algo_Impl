#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;


class MyString{

private:
        char * m_data;
        int m_size;
    
public:

MyString() {
    m_data = nullptr;
    m_size = 0 ;
}

// constructor
MyString(char * data) {

    cout << "creating " << endl;
    m_size = strlen(data);
    m_data = new char[m_size];
    memcpy(m_data , data , m_size);

}

//copy constructor

MyString(const MyString &other){

    cout << "copying" << endl;
    m_size = other.m_size;
    m_data = new char[m_size];
    memcpy(m_data , other.m_data , m_size);

}




MyString& operator=(MyString &other) {

    if (this != &other) {   // check for self assignment

        delete m_data;
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data , other.m_data , m_size);
        
    }

    return *this;
}


MyString SubStr(int s_index , int e_index) {

    MyString s;
    s.m_size = e_index - s_index + 1;
    s.m_data = new char[s.m_size];
    memcpy(s.m_data , m_data+s_index , s.m_size);
    return s;
    // int size = e_index - s_index  + 1;
    // char * data = new char[size];
    // memcpy(data , m_data+s_index , size);
    // MyString *str= new MyString(data);
    // return *str;

}

void PrintString() {

    for(int i = 0 ; i<m_size ; i++){
        cout << m_data[i];
    }
    cout << endl;
}

~MyString(){
    delete [] m_data;
}


};


int main(){


    MyString str1("Abhinav");
    MyString str2("Tiwari");
    MyString str3 = str2;
    //str1 = str2;   // invoke copy assignment

    // str3.PrintString();
    // str1.PrintString();

    MyString str6 = str1.SubStr(1 , 4);
    str6.PrintString();
    //str1.SubStr(3);

    unique_ptr<MyString> str_up = make_unique<MyString>("Abhishek");
    unique_ptr<MyString> str2_up(new MyString("jhvjhv"));

}