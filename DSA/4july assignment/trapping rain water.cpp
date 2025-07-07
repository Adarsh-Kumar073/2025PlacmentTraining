class Solution {
public:

    int solve(vector<int> & height, int prev, int idx, int middle, vector<vector<int>> & dp){
        if(idx== height.size()){
            return 0;
        }
        if(dp[prev][idx]!=-1){
            return dp[prev][idx];
        }
        int trappedWater = 0;
        if (idx > prev + 1) { 
            trappedWater = min(height[prev], height[idx]) * (idx - prev - 1) - middle;
        }

        int includeCurrent = trappedWater + solve(height, idx, idx + 1, 0, dp);
        int skipCurrent = solve(height, prev, idx + 1, middle + height[idx], dp);

        return dp[prev][idx]=max(includeCurrent, skipCurrent);
    }

    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        // vector<vector<int>>dp(height.size(), vector<int>(height.size(), -1));
        // return solve(height, 0, 1, 0, dp);
        int total = 0; 
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = height[r]; 
        
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < lmax) {
                    total += lmax - height[l]; 
                } else {
                    lmax = height[l]; 
                }
                l++; 
            } else {
                if (height[r] < rmax) {
                    total += rmax - height[r]; 
                } else {
                    rmax = height[r]; 
                }
                r--;
            }
        }
        return total; 
    }
};