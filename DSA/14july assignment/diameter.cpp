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
    int height(TreeNode* root){
        if(root== nullptr){
            return 0;
        }
        int left= height(root->left);
        int right= height(root->right);
        int i= max(left, right)+1;
        return i;
    }
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root== nullptr){
            return ans;
        }
        int LeftDia= diameterOfBinaryTree( root->left);
        int rightDia=diameterOfBinaryTree( root->right);
        int Height= height(root->left)+ height(root->right);
        ans= max(Height, max(LeftDia, rightDia));
        return ans;
    }
    
};