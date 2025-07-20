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
   bool ValidBST( TreeNode*  root, long long int left, long long int right){
    if(root== nullptr){
        return true;
    }
    if(root->val > left && root->val< right){
        return ValidBST(root->left, left, root->val) && ValidBST(root->right, root->val, right);
    }
    else
    return false;
   }
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max= 1000000000000;
        return ValidBST(root, min, max);
    }
};