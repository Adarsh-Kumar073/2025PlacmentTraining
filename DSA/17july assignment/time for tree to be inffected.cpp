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

    void setParents(TreeNode* root, int start, TreeNode* & target, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start) target= curr;
            if(curr->left){
                parent[curr->left]= curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]= curr;
                q.push(curr->right);
            }
        }

    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target= nullptr;
        unordered_map<TreeNode*, TreeNode*> parent;
        setParents(root, start, target, parent );
        queue<TreeNode*> q;
        q.push(target);
        int time=0;
        unordered_map<TreeNode*, bool>visited;
        visited[target]=true;
        while(!q.empty()){
            int sz= q.size();
            for(int i=0; i < sz; i++){
                TreeNode* curr= q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]= true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent[curr]&& !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]= true;
                }

            }
            if(!q.empty()) time++;
        }
        return time;
    }
};