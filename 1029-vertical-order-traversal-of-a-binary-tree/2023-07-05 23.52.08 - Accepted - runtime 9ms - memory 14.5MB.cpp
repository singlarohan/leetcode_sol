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
    unordered_map<int, map<int, multiset<int>>> mp;
    int left = INT_MAX, right = INT_MIN;
public:
    void dfs(int ind, int level, TreeNode*root){
        if(!root) return;
        
        mp[ind][level].insert(root -> val);

        left = min(left, ind);
        right = max(right, ind);

        dfs(ind + 1, level + 1, root -> right);
        dfs(ind - 1, level + 1, root -> left);

        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //root left right (ofc)
        dfs(0, 0, root);

        vector<vector<int>> ans;

        while(left <= right){
            ans.push_back({});

            for(auto &x:mp[left]){
                for(auto &y:x.second){
                    ans.back().push_back(y);
                }
            }
            
            left++;
        }
        return ans;
    }
};