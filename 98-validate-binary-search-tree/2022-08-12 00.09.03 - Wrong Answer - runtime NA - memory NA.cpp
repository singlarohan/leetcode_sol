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
    bool isValidBST(TreeNode* root, int min = INT_MIN, int max = INT_MAX) {
        if(root == NULL)
            return true;
        if(root -> val <= min  || root -> val >= max)
            return false;
        else
            return isValidBST(root -> left, min, root -> val) && isValidBST(root -> right, root -> val, max);
    //     if(root -> left == NULL && root -> right == NULL)
    //         return true;
    //     else if(root -> left == NULL){
    //         if( root -> right -> val > root -> val)
    //             return true;
    //         return false;
    //     }
    //     else if(root -> right == NULL){
    //         if(root -> left -> val < root -> val)            
    //             return true;
    //         return false;
    //     }
    //     else if(root -> val > root -> left -> val && root -> val < root -> right -> val){
    //         bool left = (isValidBST(root -> left));
    //         bool right = (isValidBST(root -> right));
    //         if(!left || !right)
    //             return false;
    //         else return true;
    //     }
    //     else 
    //         return false;
    // }
    }
};