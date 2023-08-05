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
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long i,ans = 0;
        TreeNode *temp;
        while(!q.empty()){
            int n = q.size();
            unsigned long long mini = q.front().second;
            while(n--){
                i = q.front().second;
                temp = q.front().first;
                if(temp -> left) q.push({temp -> left, 2 * i + 1});
                if(temp -> right) q.push({temp -> right, 2 * i + 2});
                q.pop();
                ans = max(ans, i - mini + 1);
            }
        }
        return ans;
    }
};