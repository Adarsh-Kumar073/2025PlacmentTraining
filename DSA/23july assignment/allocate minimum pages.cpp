class Solution {
public:

    
    bool solve(vector<int>& arr, int k, int max_pages) {
        int count=1;
        int sum=0;
        for(int pages: arr){
            if(pages> max_pages) return false;
            if(sum+pages> max_pages){
                count++;
                sum= pages;
                if(count>k)return false;
            }
            else{
                sum+=pages;
            }
        }
        return true;
    }

    int findPages(vector<int>& arr, int k) {
        if (k > arr.size()) {
            return -1;
        }
        int low=* max_element(arr.begin(), arr.end());
        int high= 0;
        for(int pages : arr){
            high+=pages;
        }
        int ans= high;
        while(high>=low){
            int mid= low+ (high-low)/2;
            if(solve(arr, k, mid)){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
        
    }
};