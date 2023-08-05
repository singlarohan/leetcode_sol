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
private:
    vector<int> ans;
public:
    void solve(TreeNode* root){
        if(!root) return;
        solve(root -> left);
        ans.push_back(root -> val);
        solve(root -> right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};