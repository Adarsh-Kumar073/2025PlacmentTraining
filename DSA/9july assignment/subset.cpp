class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        solve(nums, 0, path, result);
        return result;
    }
    
    void solve(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            solve(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};