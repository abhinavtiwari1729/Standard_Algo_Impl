#include <iostream>
#include <vector>

using namespace std;


bool DoesExistValue(vector<int> &values , int begin , int end , int element){

    if (begin > end )
        return false ;
    
    int mid =  begin + (end - begin)/2;
    
    if(values[mid] == element)
        return true;

    // finding sorted part of array
    if(values[begin] < values[mid-1]){   // left part is sorted 
        if (values[begin] < element  && element < values[mid-1]){
            return DoesExistValue(values , begin , mid-1 , element);
        }
        else {
            return DoesExistValue(values , mid+1 , end , element);
        }
    }
    else {  // right part is sorted

        if (values[mid+1] < element && element < values[end]){
            return DoesExistValue(values , mid+1 , end , element);
        }
        else 
            return DoesExistValue(values , begin , mid-1 , element);

    }

}


int main(){

vector<int> values = { 4 , 5 , 6 , 7 , 8 , 1 , 2};
int element;
cin>> element;
int start = 0 ;
int end = values.size()-1;
bool ans = DoesExistValue(values , start , end , element);

if (ans){
    cout << "element is present " << endl;
}
else {
    cout << "element is not present" << endl;
}

}











