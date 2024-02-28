#include<iostream>
#include<functional>

using namespace std;

int multiply(int a , int b) {

    return a*b;
}

struct entity{

    int a ;

    entity(int b): a(b) {

    }

    void func(int b){
        cout << a*b << endl;
    }

};


int main(){

    auto multiply_10 = bind(multiply , 10 , placeholders::_1);
    //cout << multiply_10(5);

    entity E(10);
    auto print_f = bind(entity::func , E , placeholders::_1);
    print_f(2);

}
