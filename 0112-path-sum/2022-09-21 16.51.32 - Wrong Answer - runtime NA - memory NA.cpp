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
    bool solve(TreeNode *root, int target){
        if(target == 0)
            return true;
        if(root == NULL)
            return false;
        return solve(root -> left, target - root -> val) || solve(root -> right, target - root -> val);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        return solve(root, targetSum);
    }
};