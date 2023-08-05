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
    int ans{};
public:
    int dfs(TreeNode *root){
        if(!root) return 0;

        int lh = dfs(root -> left);
        if(lh < 0 ) lh = 0;

        int rh = dfs(root -> right);
        if(rh < 0) rh = 0;

        ans = max(ans, root -> val + lh + rh);

        if(root -> val + max(lh, rh) >= 0) return root -> val + max(lh, rh);

        return 0;

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};