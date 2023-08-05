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
    int ans{}, original{};
    void helper(TreeNode *root, int targetSum){
        if(root == NULL)
            return;
        if(targetSum - root -> val == 0)
            ans++;
        //select current node
        helper(root -> left, targetSum - root -> val);
        helper(root -> right, targetSum - root -> val);
        //not select current node
        helper(root -> left, original);
        helper(root -> right, original);

    }
    int pathSum(TreeNode* root, int targetSum) {
        original = targetSum;
        helper(root, targetSum);
        return ans;
    }
};