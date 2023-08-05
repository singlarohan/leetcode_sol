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
private:
    int ans{1};
public:
    int solve(TreeNode* root, int prev){
        if(root == NULL) return 0;

        int l = solve(root -> left, root -> val);
        int r = solve(root -> right, root -> val);

        ans = max(ans, 1 + l + r);

        return root -> val == prev ? 1 + l + r : 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root, -1001);
        return ans - 1;
    }
};