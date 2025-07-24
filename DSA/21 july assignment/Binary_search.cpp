#include<iostream>
#include<vector>
using namespace std;

int search(int n, vector<int>& arr ){
    int left=0; 
    int right= arr.size();
    while(left>right){
        int mid= left+ (right-left)/2;
        if(mid>n){
            right= mid;
        }
        else if(mid<n){
            left= mid;
        }
        else if(mid==n){
            return mid;
        }
    }
    return -1; 
}

int recursive(int left, int right, vector<int>arr, int n){
    if(left>=right){
        return -1;
    }
    int mid= left+(right- left)/2;
    if(mid>n){
        right= mid;
    }
    else if(mid<n){
        left= mid;
    }
    return mid;
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    int idx1 = search(5, nums);
    int idx2 = recursive(0, nums.size()-1, nums,5);
    cout<<"Output of iterative approach:"<<idx1<<endl;
    cout<<"Output of recursive approach:"<<idx2<<endl;
    return 0;
}