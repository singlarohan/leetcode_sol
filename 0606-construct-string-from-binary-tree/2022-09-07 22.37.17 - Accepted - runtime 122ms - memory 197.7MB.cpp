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
    string ans;
    void solve(TreeNode *root){
        if(!root)
            return;
        ans += to_string(root -> val);
        if(root -> right || root -> left){
            ans.push_back('(');
            tree2str(root -> left);
            ans.push_back(')');
        }
        if(root -> right){
            ans.push_back('(');
            tree2str(root -> right);
            ans.push_back(')');
        }
        return;
    }
    
    string tree2str(TreeNode* root) {
        solve(root);
        return ans;
    }
};