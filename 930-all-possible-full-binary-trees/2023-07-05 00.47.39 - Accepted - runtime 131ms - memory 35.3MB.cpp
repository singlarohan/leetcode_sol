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
public:
    vector<TreeNode*> solve(int n){
        if(n == 1) return {new TreeNode(0)};

        TreeNode *root;
        vector<TreeNode*> ans;

        for(int i = 1; i <= n - 2; i += 2){

            vector<TreeNode *> left = solve(i);
            vector<TreeNode *> right = solve(n - i - 1);

            for(auto &x:left){
                for(auto &y:right){
                    root = new TreeNode(0);
                    root -> left = x;
                    root -> right = y;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        return solve(n);
    }
};