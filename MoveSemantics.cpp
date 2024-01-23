#include<iostream>
#include<string.h>

using namespace std;


class String{

    char * m_name;
    int m_size;

    public:

    String() = default;

    String(char * name){
        
        cout << "created" << endl;
        m_size = strlen(name);
        m_name =  new char(m_size);
        memcpy(m_name , name , m_size);
    }

    String(const String &other){
        
        cout << "copied" << endl;
        m_size = other.m_size;
        m_name =  new char(m_size);
        memcpy(m_name , other.m_name , m_size);
    }


    String(String &&other) {
        cout << "moved" << endl;
        m_size = other.m_size;
        m_name = other.m_name;

        other.m_name = nullptr;
        other.m_size = 0;

    }


    String& operator=(String &&other) {

        if(this != &other) {
            cout << "move assignment" << endl;
            delete m_name;
            m_size = other.m_size;
            m_name = other.m_name;

            other.m_name = nullptr;
            other.m_size = 0;
        }

        return *this;

    }





    ~String(){

        cout << "distroyed" << endl;
        delete m_name ;
    }

    void PrintString() {

        for(int i = 0 ; i<m_size ; i++){
            cout << m_name[i];
        }
        cout << endl;
    }
};



class Entity{

    public:

    Entity(const String &name)
        :m_data(name)
    {

    }

    Entity(String &&name) 
        :m_data(std::move(name))
    {

    }
    void PrintName(){
        m_data.PrintString();
    }


    private:
    String m_data;
};

int main(){

    //String str1("Abhinav");
    // Entity en1("Tiwari");
    // en1.PrintName();
    //str1.PrintString();

    String apple = "Apple";
    String dest;

    dest = std::move(apple);
    dest.PrintString();
    apple.PrintString();

    cin.get();

}