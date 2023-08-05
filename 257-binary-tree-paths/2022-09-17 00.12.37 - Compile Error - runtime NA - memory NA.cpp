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
    vector<string> ans;
    void solve(TreeNode *root, string &temp){
        if(root == NULL)
            return;
        if(!root -> left && !root -> right){
            ans.push_back(temp + to_string(root -> val));
            return;
        }
        solve(root -> left, temp + to_string(root -> val) + "->");
        solve(root -> right, temp + to_string(root -> val) + "->");
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        solve(root, temp);
        return ans;
    }
};