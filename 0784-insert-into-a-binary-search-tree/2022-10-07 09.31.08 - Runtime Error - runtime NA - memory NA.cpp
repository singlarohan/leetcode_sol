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
    void dfs(TreeNode *root, int val){
        if(!root -> left && !root -> right){
            if(root -> val > val)
                root -> left = new TreeNode(val);
            else
                root -> right = new TreeNode(val);
            return;
        }
        if(root -> val > val)
            dfs(root -> left, val);
        else
            dfs(root -> right, val);
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
        dfs(root , val);
        return root;
    }
};