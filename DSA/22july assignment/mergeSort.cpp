#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int>nums1, vector<int>nums2){
    int n= nums1.size();
    int m= nums2.size();
    int i=0, j=0, k=0;
    vector<int> ans;
    while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else{
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while (i < n) {
        ans.push_back(nums1[i]);
        i++;
    }
    while (j < m) {
        ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}

vector<int> mergeSort(vector<int> arr){
    if(arr.size()==1){
        return arr;
    }
    int n= arr.size();
    vector<int> firstHalf(arr.begin(), arr.begin() + n / 2);
    vector<int> secondHalf(arr.begin() + n / 2, arr.end());
    vector<int>nums1=mergeSort(firstHalf);
    vector<int> nums2=mergeSort(secondHalf);
    vector<int> ans= merge(nums1, nums2);
    return ans;
}

int main(){
    vector<int>nums={4,3,5,2,7,8,5,50};
    vector<int>sorted= mergeSort(nums);
    for(int n: sorted){
        cout<<n<<",";
    }
    
    return 0;
}