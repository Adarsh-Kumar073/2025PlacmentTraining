class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result(2, -1);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) 
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (left >= nums.size() || nums[left] != target) 
            return result;  
        
        result[0] = left;  
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        result[1] = right;

        return result;
    }
};
