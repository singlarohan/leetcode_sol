/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
public:
    TreeNode *solve(TreeNode *root, TreeNode* p, TreeNode* q){
        if(root == p || root == q || root == NULL) 
            return root;

        TreeNode *left = solve(root -> left, p, q);
        TreeNode *right = solve(root -> right, p, q);

        if(left && right) return root;
        return left ? left : right;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};