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
    unordered_map<TreeNode*, int> mp0;
    unordered_map<TreeNode*, int> mp1;

    int solve(TreeNode *root, bool ifcan){
        if(root == NULL)
            return 0;
        int rob{0};
        if(ifcan){
            if(mp1[root] != 0)
                return mp1[root];
            rob = root -> val + solve(root -> left, !ifcan) + solve(root -> right, !ifcan);
        }
        else if(mp0[root] != 0)
            return mp0[root];
        int notrob = solve(root -> left, true) + solve(root -> right, true);
        if(ifcan)
            mp1[root] = max(rob, notrob);
        else
            mp0[root] = max(rob, notrob);
        return max(rob, notrob);
    }
    
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};