/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<vector<int>> paths;
   void solve(TreeNode* root, vector<int> ans,int targetSum){
    if(root== nullptr){
        return;
    }
    ans.push_back(root->val);
    if(root->left== nullptr && root->right== nullptr && root->val == targetSum){
        paths.push_back(ans);
    }
    solve(root->left, ans, targetSum- root->val);
    solve(root->right, ans, targetSum- root->val);
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root== nullptr){
            return {};
        }
        vector<int>ans;
        solve(root, ans, targetSum);
        return paths;
    }
};