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
    int helper(TreeNode *root, long long targetSum){
        if(!root) return 0;

        int ans = (targetSum - root -> val == 0);
        
        int lh = helper(root -> left, targetSum - root -> val);
        int rh = helper(root -> right, targetSum - root -> val);

        return ans + lh + rh;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        int ans = helper(root, targetSum);
        
        int lh = pathSum(root -> left, targetSum);
        int rh = pathSum(root -> right, targetSum);

        return ans + lh + rh;
    }
};