class Solution {
public:

    bool solve(vector<int>& piles, int h, int mid){
        long long hours = 0;
        for(int i : piles){
            hours += (i + mid - 1) / mid;  
        }
        return hours <= h;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int high= *max_element(piles.begin(), piles.end());
        int low= 1;
        if(h== piles.size()){
            return high;
        }
        int ans= high;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(solve(piles, h, mid)){
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