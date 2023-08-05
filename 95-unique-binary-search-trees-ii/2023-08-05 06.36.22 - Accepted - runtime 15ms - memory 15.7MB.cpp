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
    vector<TreeNode*> solve(int i, int n){
        if(i > n) return {NULL};
        if(i == n) return {new TreeNode(i)};
        
        vector<TreeNode*> ans;
        for(int j = i; j <= n; j++){
            //for left
            vector<TreeNode*> left = solve(i, j - 1);
            vector<TreeNode*> right = solve(j + 1, n);

            for(auto x:left){
                for(auto y:right){
                    TreeNode *temp = new TreeNode(j);
                    temp -> left = x;
                    temp -> right = y;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};