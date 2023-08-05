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
    vector<pair<double, int>> ans;
    
    int height(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1 + max(height(root -> left), height(root -> right));
    }
    
    void solve(TreeNode *root, int h){
        if(root == NULL)
            return;
        ans[h].first += root -> val;
        ans[h].second++;
        solve(root -> left, h + 1);
        solve(root -> right, h + 1);
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        int h = height(root);
        ans = vector<pair<double, int>> (h, {0, 0});
        solve(root , 0);
        vector<double> temp(h, 0);
        for(int i = 0; i < ans.size(); i++){
            temp[i] = ans[i].first/ans[i].second;
        }
        return temp;
    }
};