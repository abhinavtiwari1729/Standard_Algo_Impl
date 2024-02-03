#include<iostream>

using namespace std;

class Collection{

    private :
        int * data;
    
    
    public:

    Collection(){
        data = new int[10];
    }

    ~Collection(){
        delete[] data;
    }

    int& operator[](int index) {
        return data[index];
    }

     const int& operator[] (int index) const {
        return data[index];
    }

};



int main(){

    Collection c1;
    c1[0] = 2;
    cout << c1[0];

    return 0;

}