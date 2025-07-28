class Solution {
public:
    int solve(int mid, int k, vector<int>&nums){
        int split = 1;
        int sum =0;
        for(int i : nums){
            if(sum+i<=mid){
                sum+=i;
            }else{
                sum=i;
                split++;
            }
        }
        return split<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high =0;
        for(int i : nums){
            low = max(low,i);
            high+=i;
        }
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;

            if(solve(mid,k,nums)){
                ans = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

// class Solution {
// public:

//     int ans = INT_MAX;
//     vector<vector<int>> dp;

//     int solve(vector<int> &nums, int k, int st){
//         if(k == 0 and st<nums.size()) return -1;
//         if(st==nums.size() and k > 0) return -1;
//         if(k==0 and st == nums.size()) return 0;
//         if(dp[st][k] != -1) return dp[st][k];
   
//         int sum = 0;
//         int ans = INT_MAX;

//         for(int i =st; i<nums.size(); i++)
//         {
//             sum += nums[i];
//             int temp = solve(nums,k-1,i+1);
//             if(temp != -1) 
//             {
//                 temp = max(temp,sum);
//                 ans = min(ans,temp);
//             }
//         }

//         return dp[st][k] = ans;
//     }


//     int splitArray(vector<int>& nums, int k) {

//         dp.resize(nums.size()+1, vector<int> (k+1,-1));
//         return solve(nums,k,0);
        
//     }
// };