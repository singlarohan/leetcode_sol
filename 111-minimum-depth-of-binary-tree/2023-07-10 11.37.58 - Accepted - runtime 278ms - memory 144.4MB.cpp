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
private:
    int ans{INT_MAX};
public:
    void height (TreeNode *root, int count){
        if(!root) return;
        
        if(root -> left == NULL && root -> right == NULL)
            ans = min(ans, count);
        height(root -> left, count + 1);
        height(root -> right, count + 1);

        return;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        height(root, 1);
        return ans;
    }
};