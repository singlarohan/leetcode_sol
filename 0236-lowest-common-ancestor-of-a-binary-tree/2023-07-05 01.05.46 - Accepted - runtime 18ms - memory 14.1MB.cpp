/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *lca;
public:
    int solve(TreeNode *root, int p, int q){
        if(root == NULL) return 0;

        int ans = root -> val == p || root -> val == q;

        ans += solve(root -> left, p, q);
        ans += solve(root -> right, p, q);
        
        if(ans == 2) {
            lca = root;
            return -1;
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p -> val, q -> val);
        return lca;
    }
};