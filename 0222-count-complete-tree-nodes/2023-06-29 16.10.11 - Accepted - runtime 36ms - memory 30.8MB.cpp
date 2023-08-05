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
    int rightHeight(TreeNode *root){
        int n = 0;
        while(root){
            root = root -> right;
            n++;
        }
        return n;
    }
    int leftHeight(TreeNode *root){
        int n = 0;
        while(root){
            root = root -> left;
            n++;
        }
        return n;
    }
    int countNodes(TreeNode* root) {
        int rh = rightHeight(root);
        int lh = leftHeight(root);
        if(rh == lh) return (1 << lh) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};