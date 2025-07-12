class Solution {
public:

    int solve(int s, int e, vector<int>& nums, vector<int>&dp){
        if(s>e){
            return 0;
        }

        if(dp[s]!=-1){
            return dp[s];
        }
        dp[s]=max(solve(s+1,e,nums,dp),solve(s+2,e,nums,dp)+nums[s]);
        return dp[s];
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        int ans1= solve(0,nums.size()-2,nums,dp1);
        int ans2= solve(1,nums.size()-1,nums, dp2);
        return max(ans1,ans2);
    }
};