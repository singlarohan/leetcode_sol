/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *helper(TreeNode *root, TreeNode* p, TreeNode* q, long maxi, long mini){
        if(!root || p -> val >= maxi || p -> val <= mini 
                 || q -> val >= maxi || q -> val <= mini)
            return NULL;
        TreeNode* l = helper(root -> left, p, q, root -> val, mini);
        if(l != NULL) return l;

        TreeNode* r = helper(root -> right, p, q, maxi, root -> val);
        if(r != NULL) return r;
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q, LONG_MAX, LONG_MIN);
    }
};