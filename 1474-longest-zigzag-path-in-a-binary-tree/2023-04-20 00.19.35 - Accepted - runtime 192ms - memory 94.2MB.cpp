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
    int solve(TreeNode *root, int curr, int dir){
        //dir == 0 last moved left, dir == 1, last moved right
        if(root == NULL)
        return curr;
        if(dir == 0) return max(solve(root -> right, curr + 1, 1), solve(root -> left, 1, 0));
        else return max(solve(root -> left, curr + 1, 0), solve(root -> right, 1, 1));
    }

    int longestZigZag(TreeNode* root) {
        return solve(root, 0, 0) - 1;
    }
};