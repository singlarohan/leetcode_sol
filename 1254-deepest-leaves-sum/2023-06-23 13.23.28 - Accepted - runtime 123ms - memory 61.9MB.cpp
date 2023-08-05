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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int ans{};
        while(!q.empty()){
            int n = q.size();
            ans = 0;
            while(n--){
                ans += q.front() -> val;
                if(q.front() -> left) q.push(q.front() -> left);
                if(q.front() -> right) q.push(q.front() -> right);
                q.pop();
            }
        }   
        return ans;
    }
};