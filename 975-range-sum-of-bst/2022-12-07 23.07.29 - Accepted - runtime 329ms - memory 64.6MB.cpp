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

    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans{};
        auto solve = [&](TreeNode* root, auto &&self){
            if(!root) return;
            if(root -> val >= low && root -> val <= high)
                ans += root -> val;
            if(root -> val > low) self(root -> left, self);
            if(root -> val < high) self(root -> right, self);
        };     
        solve(root, solve);
        return ans;
    }
};