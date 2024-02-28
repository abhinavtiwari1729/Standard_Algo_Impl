#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums , int start , int end) {

    int pivot = nums[end] ;

    int i = start;
    int j = start;
    while(j <= end-1) {

        if (nums[j] < pivot) {
            swap(nums[i] , nums[j]);
            i++; 
            j++;
        }
        else{
            j++;
        }
    }

    swap(nums[end] , nums[i]);

    return i ;
}

void QuickSort(vector<int> &nums , int start , int end) {

    if (start >= end)
        return ;
    
    int pi = partition(nums , start , end);
    QuickSort(nums , start , pi-1);
    QuickSort(nums , pi+1 , end);
}

int main(){

    vector<int> nums = {13 , 1 ,  6 ,  15 , 10 ,  9 , 3};
    QuickSort(nums , 0 , nums.size()-1);

    for(auto num : nums){
        cout << num << " " ; 
    }


}
