#include<iostream>
#include<string>

using namespace std;

void ReverseString(string & name , int start , int end) {

    if (start >= end)
        return ;
    
    swap(name[start] , name[end]);
    ReverseString(name , start+1 , end-1);

}

int main() {

    string name ;
    //cin >> name ;
    getline(cin , name );
    cout << name << endl ;
    ReverseString(name , 0 , name.size()-1);

    cout << name << endl;

}