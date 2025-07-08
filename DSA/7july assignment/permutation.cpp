class Solution {
public:

    void solve(vector<int>& nums, vector<bool> visited, vector<int> &res, vector<vector<int>> &ans){
        if(res.size()== nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0; i< nums.size(); i++){
            if(visited[i]!= true){
                visited[i]= true; 
                res.push_back(nums[i]);
                solve(nums, visited, res, ans);
                res.pop_back();
                visited[i]= false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> visited(n, false);
        solve(nums, visited, res, ans);
        return ans;
        
    }
};