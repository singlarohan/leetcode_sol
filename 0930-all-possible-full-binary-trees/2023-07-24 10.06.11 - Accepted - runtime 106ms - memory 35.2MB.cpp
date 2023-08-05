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
    // vector<vector<TreeNode *>> dp;
public:
    vector<TreeNode*> solve(int n){
        if(n == 1) return {new TreeNode(0)};

        // if(!dp[(n + 1)/2].empty()) return dp[(n + 1)/2];
        TreeNode *root;
        vector<TreeNode*> ans;

        for(int i = 1; i <= n - 2; i += 2){

            vector<TreeNode *> left = solve(i);
            vector<TreeNode *> right = solve(n - i - 1);

            for(auto &x:left){
                for(auto &y:right){
                    root = new TreeNode(0, x, y);
                    ans.push_back(root);
                }
            }
        }
        // return dp[(n + 1)/2] = ans;
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        // dp = vector<vector<TreeNode*>> ((n + 1)/2 + 1, vector<TreeNode*> ());
        return solve(n);
    }
};