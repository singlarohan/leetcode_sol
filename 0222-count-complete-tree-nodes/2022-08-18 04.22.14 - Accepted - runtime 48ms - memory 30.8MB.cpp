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
    int heightl(TreeNode *root){
        if(!root)
            return 0;
        return 1 + heightl(root -> left);
    }
    int heightr(TreeNode *root){
        if(!root)
            return 0;
        return 1 + heightr(root -> right);
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int hl = heightl(root), hr = heightr(root);
        if(hl == hr)
            return pow(2, hr) - 1;
        int l = countNodes(root -> left);
        int r = countNodes(root -> right);
        return 1 + l + r;
    }
};