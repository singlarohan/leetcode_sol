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
    bool isValidBST(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL)
            return true;
        else if(root -> left == NULL){
            if( root -> right -> val > root -> val)
                return true;
            return false;
        }
        else if(root -> right == NULL){
            if(root -> left -> val < root -> val)            
                return true;
            return false;
        }
        else if(root -> val > root -> left -> val && root -> val < root -> right -> val){
            bool left = (isValidBST(root -> left));
            bool right = (isValidBST(root -> right));
            if(!left || !right)
                return false;
            else return true;
        }
        else 
            return false;
    }
};