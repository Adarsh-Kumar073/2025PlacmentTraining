#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int start, int end){
    int pivot= arr[start];
    int i= start+1;
    int j= end;
    while (i <= j) {
        while (i <= end && arr[i] <= pivot) i++;
        while (j >= start && arr[j] > pivot) j--;

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[start], arr[j]);

    return j; 
}

void quickSort(vector<int> & arr, int start, int end){
    if(start>= end){
        return;
    }
    int idx= partition(arr, start, end);
    quickSort(arr, start, idx-1);
    quickSort(arr, idx+1, end);
}

int main(){
    vector<int> nums={9,8,7,6,5,4,3,2,1};
    quickSort(nums, 0, nums.size()-1);
    for(int n: nums){
        cout<<n<<",";
    }
    return 0;
}