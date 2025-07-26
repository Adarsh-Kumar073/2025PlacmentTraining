class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (right+left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
        
    }
};