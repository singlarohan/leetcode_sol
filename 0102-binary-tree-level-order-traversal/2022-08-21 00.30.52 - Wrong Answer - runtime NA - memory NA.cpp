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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> temp;
        if(!root)
            return v;
        TreeNode *curr;
        queue<TreeNode *> q;
        int i{0};
        q.push(root);
        while(!q.empty() || !curr){
            TreeNode *curr = q.front();
            if(curr -> left)
            q.push(curr -> left);
            if(curr -> right)
            q.push(curr -> right);
            temp.push_back(curr -> val);
            i++;
            q.pop();
            if(v.size() == log2(i+1) - 1){
                v.push_back(temp);
                temp.clear();
            }
        }
        if(!temp.empty())
        v.push_back(temp);
        return v;
    }
};