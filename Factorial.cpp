#include<iostream>

using namespace std;

long long factorial(long long number) {

    if (number <= 0)
        return 1;
    else 
        return (number * factorial(number-1));
}




int main(){

    long long ans = factorial(20);
    cout << ans;
}