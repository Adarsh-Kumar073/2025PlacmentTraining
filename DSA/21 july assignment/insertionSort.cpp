#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& arr){
    int n= arr.size();
    for(int i=1; i<n; i++){
        int curr= arr[i];
        int j= i-1;
        while(j>=0 && arr[j]>curr){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]= curr;
    }
}

int main(){
    vector<int> nums={4,5,3,6,2,27,8,12};
    insertionSort(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<",";
    }
    return 0;
}