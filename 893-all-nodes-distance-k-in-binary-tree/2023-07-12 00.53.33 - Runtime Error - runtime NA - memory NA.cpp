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
    vector<int> ans;
    int k;
public:
    void solve(TreeNode *root, TreeNode *target, TreeNode *parent, int depth){
        if(depth == k) {
            if(root != target)
            ans.push_back(root -> val);
            return;
        }

        if(root == target){
            if(parent)
            solve(parent, target, NULL, 1);
            if(root -> left)
            solve(root -> left, target, root, 1);
            if(root -> right)
            solve(root -> right, target, root, 1);
            return;
        }

        if(root -> left) solve(root -> left, target, root, depth == -1 ? -1 : depth + 1);
        if(root -> right) solve(root -> right, target, root, depth == -1 ? -1 : depth + 1);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k1) {
        k = k1;
        solve(root, target, NULL, -1);
        return ans;
    }
};