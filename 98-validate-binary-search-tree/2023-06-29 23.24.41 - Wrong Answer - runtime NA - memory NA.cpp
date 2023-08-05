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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        int ans = true;
        if(root -> left){
            ans = ans & (root -> left -> val < root -> val) & (isValidBST(root -> left));
        }
        if(root -> right){
            ans = ans & (root -> right -> val > root -> val) & (isValidBST(root -> right));
        }
        return ans;
    }
};