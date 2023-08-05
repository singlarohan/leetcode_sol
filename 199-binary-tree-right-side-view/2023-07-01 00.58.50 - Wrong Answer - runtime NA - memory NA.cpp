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
    void dfs(TreeNode *root){
        if(!root) return;
        ans.push_back(root -> val);
        if(root -> right) dfs(root -> right);
        else dfs(root -> left);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root);
        return ans;
    }
};