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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.top();
            q.pop();
            while(temp){
                ans.push_back(temp -> val);
                if(temp -> right) q.push(temp -> right);
                temp = temp -> left;
            }
        }
        return ans;
    }
};