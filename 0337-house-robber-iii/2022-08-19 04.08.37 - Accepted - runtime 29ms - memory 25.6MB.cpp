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
    unordered_map<TreeNode*, int> mp;

    int solve(TreeNode *root, bool ifcan){
        if(root == NULL)
            return 0;
        if(mp.find(root) != mp.end() && ifcan)
            return mp[root];
        int rob{0};
        if(!ifcan)
            return solve(root -> left, true) + solve(root -> right, true);
        rob = root -> val + solve(root -> left, !ifcan) + solve(root -> right, !ifcan);
        int notrob = solve(root -> left, true) + solve(root -> right, true);
        return mp[root] = max(rob, notrob);
    }
    
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};