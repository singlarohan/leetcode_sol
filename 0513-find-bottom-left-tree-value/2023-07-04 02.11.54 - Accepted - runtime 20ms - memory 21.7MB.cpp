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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans{};
        q.push(root);
        while(!q.empty()){
            ans = q.front() -> val;
            int size = q.size();
            while(size--){
                if(q.front() -> left)
                q.push(q.front() -> left);
                if(q.front() -> right)
                q.push(q.front() -> right);
                q.pop();
            }
        }
        return ans;
    }
};