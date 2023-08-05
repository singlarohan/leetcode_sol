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
        if(root -> left == NULL && root -> right == NULL){
            if(target - root -> val == 0)
                return true;
            return false;
        }
        bool left = false, right = false;
        if(root -> left)
            left = solve(root -> left, target - root -> val);
        if(root -> right)
            right = solve(root -> right, target - root -> val);
        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        return solve(root, targetSum);
    }
};