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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool turn = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> curr;
            while(size--){
                TreeNode *temp = q.front();
                q.pop();
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                curr.push_back(temp -> val);
            }
            if(turn) reverse(curr.begin(), curr.end());
            ans.push_back(curr);
            turn = !turn;
        }
        return ans;
    }
};