class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long sum=0;
        int res=0;
        int i=0;

        sort(nums.begin(), nums.end());
        for(int j=0; j<nums.size(); j++){
            sum+=nums[j];
            long curr = nums[j];
            while(((curr*(j-i+1))-sum) > k){
                sum-=nums[i++];
            }
            res=max(res,(j-i+1));
        }
        return res;
    }
};