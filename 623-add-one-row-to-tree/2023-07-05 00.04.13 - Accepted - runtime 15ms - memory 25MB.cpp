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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *temp = new TreeNode(val);
            temp -> left = root;
            return temp;
        }
        queue<TreeNode *> q;
        q.push(root);

        int level = 1;
        TreeNode *top;
        while(!q.empty() && level != depth){
            int size = q.size();
            while(size--){
                top = q.front();
                q.pop();
                if(level == depth - 1){
                    TreeNode *temp = new TreeNode(val);
                    temp -> left = top -> left;
                    top -> left = temp;
                    temp = new TreeNode(val);
                    temp -> right = top -> right;
                    top -> right = temp;
                }
                else{
                    if(top -> left) q.push(top -> left);
                    if(top -> right) q.push(top -> right);
                }
            }
            level++;
        }
        return root;
    }
};