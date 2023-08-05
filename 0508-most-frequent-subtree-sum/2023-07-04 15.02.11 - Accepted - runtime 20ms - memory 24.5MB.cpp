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
    unordered_map<int, int> mp;
    int maxi = INT_MIN;
//value and frequency
public:
    int dfs(TreeNode *root){
        if(!root) return 0;
        int curr = root -> val;
        curr += dfs(root -> left);
        curr += dfs(root -> right);
        mp[curr]++;
        maxi = max(mp[curr], maxi);
        return curr;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for(auto x:mp){
            if(x.second == maxi) ans.push_back(x.first);
        }
        return ans;
    }
};