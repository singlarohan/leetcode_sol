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
    int leftHeight(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + leftHeight(root -> left);
    }

    int rightHeight(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + rightHeight(root -> right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = leftHeight(root);
        int r = rightHeight(root);
        return (abs(l - r) <= 1) && isBalanced(root -> left) && isBalanced(root -> right);
    }
};