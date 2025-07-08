class Solution {
public:

    void solve(vector<int>& candidates, int target, int idx, vector<int>& res, vector<vector<int>>& ans){
        if( target==0){
            ans.push_back(res);
            return;
        }
        if(idx== candidates.size() || target< 0){
            return;
        }
        
        for(int i= idx; i< candidates.size(); i++){
            res.push_back(candidates[i]);  
            solve(candidates, target - candidates[i], i, res, ans); 
            res.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>res;
        solve(candidates, target, 0, res, ans);
        return ans;
    }
};