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
    vector<int> ans;
    int rheight = 0;
public:
    void dfs(TreeNode *root, int curr){
        if(!root) return;
        
        if(curr > rheight)
        ans.push_back(root -> val);
        rheight = max(curr, rheight);

        dfs(root -> right, curr + 1);
        dfs(root -> left, curr + 1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};