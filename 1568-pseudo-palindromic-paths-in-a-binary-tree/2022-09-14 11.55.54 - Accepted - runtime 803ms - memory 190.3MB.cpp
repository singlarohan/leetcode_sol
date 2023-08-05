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
    unordered_map<int, int> mp;
    int solve(TreeNode *root){
        if(!root)
            return 0;
        mp[root -> val]++;
        if(root -> left == NULL && root -> right == NULL){
            int count{};
            for(auto it:mp){
                if(it.second % 2 != 0)
                    count++;
                if(count > 1){
                    mp[root -> val]--;
                    return 0;
                }
            }
            mp[root -> val]--;
            return 1;
        }
        int ans{};
        if(root -> left)
            ans += solve(root -> left);
        if(root -> right)
            ans += solve(root -> right);
        mp[root -> val]--;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root);
    }
};