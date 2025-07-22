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
    vector<int> v;
    void traverse(TreeNode* root){
        if(root== nullptr){
            return;
        }
        v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        int sz= v.size();
        for(int i=0; i<sz; i++){
            for(int j=i; j<sz; j++){
                if(v[i]+ v[j]== k && j!=i){
                    return true;
                }
            }
        }
        return false;
    }
};