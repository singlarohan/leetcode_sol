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
    int ans{}, original{};
    void helper(TreeNode *root, int targetSum){
        if(targetSum == 0){
            ans++;
            return;
        }
        if(root == NULL)
            return;
        helper(root -> left, targetSum - root -> val);
        helper(root -> right, targetSum - root -> val);
    }
    void solve(TreeNode *root, int targetSum){
        if(root == NULL)
            return;
        helper(root, targetSum);
        solve(root -> left, targetSum);
        solve(root -> right, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        original = targetSum;
        solve(root, original);
        return ans/2;
    }
};