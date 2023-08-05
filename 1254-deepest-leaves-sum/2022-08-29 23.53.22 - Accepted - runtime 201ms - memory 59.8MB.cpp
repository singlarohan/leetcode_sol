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
    int Theight(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1 + max(Theight(root -> left), Theight(root -> right));
    }
    
    int solve(TreeNode *root, int h, int height){
        if(root == NULL)
            return 0;
        if(h == height)
            return root -> val;
        return solve(root -> left,h +1, height) + solve(root -> right, h+1, height);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int height = Theight(root);
        
        return solve(root, 1, height);
    }
};