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
    string ans;
    string tree2str(TreeNode* root) {
        ans.push_back(root -> val + '0');
        if(root -> left){
            ans.push_back('(');
            tree2str(root -> left);
            ans.push_back(')');
        }
        if(root -> right){
            ans.push_back('(');
            tree2str(root -> right);
            ans.push_back(')');
        }
        return ans;
    }
};