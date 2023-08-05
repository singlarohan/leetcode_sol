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
        if(root == NULL)
            return ans;
        queue<TreeNode*> tq;
        bool rev = false;
        tq.push(root);
        while(!tq.empty()){
            vector<int> temp;
            int k = tq.size();
            while(k--){
                TreeNode* tem = tq.front();
                if(tem -> left)
                    tq.push(tem -> left);
                if(tem -> right)
                    tq.push(tem -> right);
                temp.push_back(tem -> val);
                tq.pop();
            }
            if(rev) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            rev = !rev;
        }
        return ans;
    }
};