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
    int solve(TreeNode *root){
        if(root -> left == NULL && root -> right == NULL) return root -> val;

        int ans = solve(root -> left);

        if(root -> right != NULL && 
                        !(root -> right -> left == NULL && root -> right -> right == NULL))
        ans += solve(root -> right);
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || !(root -> left || root -> right)) return 0;
        return solve(root);
    }
};