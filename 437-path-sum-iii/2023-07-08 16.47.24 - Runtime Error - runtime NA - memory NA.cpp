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
    int helper(TreeNode *root, int targetSum){
        if(root == NULL)
            return 0;

        return (targetSum - root -> val == 0) + helper(root -> left, targetSum - root -> val)
                                              + helper(root -> right, targetSum - root -> val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        return helper(root, targetSum) + pathSum(root -> left, targetSum) 
                                       + pathSum(root -> right, targetSum);
    }
};