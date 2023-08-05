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
    bool isSymmetric(TreeNode* root) {
        //if left center right = right center left then symmetric 
        auto solve = [&](TreeNode *root1, TreeNode *root2, auto &&self){
            if((!root1 && root2) || (root1 && !root2)) return false;
            if(!root1 && !root2) return true;
            return root1 -> val == root2 -> val && self(root1 -> left, root2 -> right, self);
        };
        return solve(root, root, solve);
    }
};