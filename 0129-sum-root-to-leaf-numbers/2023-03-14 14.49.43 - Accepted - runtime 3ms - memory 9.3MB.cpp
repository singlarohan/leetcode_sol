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
            if(!(node -> left || node -> right)) {
                curr *= 10;
                curr += node -> val;
                ans += curr;
                return;
            }
            if(node -> left)
            self(node -> left, curr * 10 + node -> val, self);
            if(node -> right)
            self(node -> right, curr * 10 + node -> val, self);
            return;
        };
        solve(root, 0, solve);
        return ans;
    }
};