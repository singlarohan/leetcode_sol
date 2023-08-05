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
        if(root -> val < val){
            if(root -> right)
                dfs(root -> right, val);
            else
                root -> right = new TreeNode(val);
        }
        if(root -> val > val){
            if(root -> left)
                dfs(root -> left, val);
            else
                root -> left = new TreeNode(val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
        dfs(root , val);
        return root;
    }
};