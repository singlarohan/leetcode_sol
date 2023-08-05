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
    int ans;
public:
    int solve(TreeNode *root, int count, int k){
        if(!root) return 0;
        int l = solve(root -> left, count, k);
        if(1 + l + count == k)
            ans = root -> val;
        if(ans != 0) return -1e9;
        int r = solve(root -> right, 1 + l + count, k);
        return 1 + l + r;
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root, 0, k);
        return ans;
    }
};