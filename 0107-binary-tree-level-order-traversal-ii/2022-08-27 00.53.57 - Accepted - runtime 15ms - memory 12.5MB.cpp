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
    int height(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1 + max(height(root -> left), height(root -> right));
    }
    
    void solve(int height, vector<vector<int>> &ans, TreeNode *root){
        if(height < 0 || root == NULL)
            return;
        ans[height].push_back(root -> val);
        solve(height - 1, ans, root -> left);
        solve(height - 1, ans, root -> right);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans(h);
        solve(h - 1, ans, root);
        return ans;
    }
};