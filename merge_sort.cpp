#include<iostream>
#include<vector>

using namespace std;


void merge(vector<int> &nums , int start , int mid , int end) {

    int size = nums.size();
    vector<int> temp( end - start + 1 , 0 );
    int i = start , j = mid ; 
    int temp_start = 0 ;

    while(i <= mid-1 && j <= end) {

        if(nums[i] < nums[j]) {
            temp[temp_start] = nums[i];
            i++;
            temp_start++;

        }
        else {
            temp[temp_start] = nums[j];
            j++;
            temp_start++;

        }
    }

    while( i <= mid-1) {
        temp[temp_start] = nums[i];
        i++;
        temp_start++;
    }
    while( j <= end) {
        temp[temp_start] = nums[j];
        j++;
        temp_start++;
    }

    temp_start = 0;

    for(int index = start ; index <= end ; index++) {
        nums[index] = temp[temp_start];
        temp_start++;
    }
}


void _mergesort(vector<int> &nums , int start , int end) {

        if (start < end) {
            int mid = start + (end - start)/2;
            _mergesort(nums , start , mid);
            _mergesort(nums , mid+1 , end);
            merge(nums , start , mid+1 , end);
        }
}


void MergeSort(vector<int> &nums) {

    int n = nums.size() -1 ;
    _mergesort(nums , 0 , n );

}

int main() {

    vector<int> nums = {2 , 9 , 6 , 4 , 1 , 0 , 8 , 100 , -2 , 5 , 6 , 55} ;
    MergeSort(nums);
    for(auto &num : nums){
        cout << num << " ";
    }

}