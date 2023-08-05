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
        if(root == NULL && target == 0){
            ans.push_back(temp);
            return;
        }
        if(root == NULL)
            return;
        temp.push_back(root -> val);
        solve(root -> left, target - root -> val, temp, ans);
        if(target - root -> val != 0)
        solve(root -> right, target - root -> val, temp, ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> temp;
        solve(root, targetSum, temp, ans);
        return ans;
    }
};