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
    void solve(TreeNode* root, int target, vector<int> &temp, vector<vector<int>> &ans){
        if(root == NULL)
            return;
        temp.push_back(root -> val);
        if(target - root -> val == 0){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        solve(root -> left, target - root -> val, temp, ans);
        solve(root -> right, target - root -> val, temp, ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum, temp, ans);
        return ans;
    }
};