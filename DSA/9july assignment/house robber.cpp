class Solution {
public:

    int solve(int n,vector<int>&nums, vector<int>&dp){
        if(n>=nums.size()){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = max(solve(n+1,nums,dp),nums[n]+solve(n+2,nums,dp));
        return dp[n];
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==0){
            return 0;
        }
        int i=0;
        vector<int> dp(nums.size()+1,-1);
        int ans = solve(i,nums,dp);
        return ans;
    }
};