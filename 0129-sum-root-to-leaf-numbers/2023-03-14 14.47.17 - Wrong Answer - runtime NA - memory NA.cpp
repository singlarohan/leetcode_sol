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
    int sumNumbers(TreeNode* root) {
        int ans{};
        auto solve = [&](TreeNode* node, int curr, auto &&self){
            if(!node) {
                ans += curr;
                return;
            }
            self(node -> left, curr * 10 + node -> val, self);
            self(node -> right, curr * 10 + node -> val, self);
            return;
        };
        solve(root, 0, solve);
        return ans/2;
    }
};