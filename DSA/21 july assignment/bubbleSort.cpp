#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>&arr){
    int n=arr.size()-1;
    bool swaped;
    for(int i=0;i<n;i++){
        swaped= false;
        for(int j=0; j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaped= true;
            } 
        }
        if(!swaped) break;
    }
}

int main(){
    vector<int> nums={4,5,3,6,2,27,8,12};
    bubbleSort(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<",";
    }
    return 0;
}