#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>& arr){
    int n= arr.size();
    for(int i=0; i<n-1; i++ ){
        int idx=i;
        for(int j=i; j<n; j++){
            int mini= min(arr[j], arr[idx]);
            if(mini== arr[j]) idx=j;
        }
        swap(arr[i], arr[idx]);
    }

}

int main(){
    vector<int> nums={4,5,3,6,2,27,8,12};
    selection_sort(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<",";
    }
    return 0;
}