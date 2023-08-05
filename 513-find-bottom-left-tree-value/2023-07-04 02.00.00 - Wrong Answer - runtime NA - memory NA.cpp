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
    //row number, col number, value
public:
    void dfs(int row, int col, TreeNode*root){
        if(root == NULL) return;

        if(row > ans[0] || (row == ans[0] && col < ans[1])) ans = {row, col, root -> val};
        
        dfs(row + 1, col - 1, root -> left);
        dfs(row + 1, col + 1, root -> right);

        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        ans = vector<int> (3, -1);
        dfs(0, 0, root);
        return ans[2];
    }
};