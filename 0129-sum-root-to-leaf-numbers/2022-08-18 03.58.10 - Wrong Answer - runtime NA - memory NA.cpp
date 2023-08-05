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
    int solve(TreeNode* root, double ans){
        if(root == NULL)
            return ans/10;
        // ans = (ans + root -> val)*10;
        int r = solve(root -> right, (ans + root -> val)*10);
        int l = solve(root -> left, (ans + root -> val)*10);
        return r+l;
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root, 0)/2;
    }
};