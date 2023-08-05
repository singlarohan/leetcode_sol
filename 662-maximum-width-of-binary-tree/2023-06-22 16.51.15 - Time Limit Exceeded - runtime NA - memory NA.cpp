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
    int widthOfBinaryTree(TreeNode* root) {
        //using BFS
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        while(!q.empty()){
            while(!q.empty() && q.front() == NULL) q.pop();
            int n = q.size();
            int count = 1;
            while(n--){
                if(q.front() != NULL) {
                    ans = max(count, ans);
                    q.push(q.front() -> left);
                    q.push(q.front() -> right);
                }
                else{
                    q.push(NULL);
                    q.push(NULL);
                }
                q.pop();
                count++;
            }
        }
        return ans;
    }
};