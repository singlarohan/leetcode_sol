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
    unordered_map<int, unordered_map<int, vector<int>>> mp;
    int left = INT_MAX, right = INT_MIN;
public:
    void dfs(int ind, int level, TreeNode*root){
        if(!root) return;
        
        mp[ind][level].push_back(root -> val);

        left = min(left, ind);
        right = max(right, ind);

        dfs(ind + 1, level + 1, root -> right);
        dfs(ind - 1, level + 1, root -> left);

        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //root left right (ofc)
        dfs(0, 0, root);
        // cout<<mp[left][0].empty()<<endl;
        // for(auto x:mp){
        //     for(auto y:x.second){
        //         for(auto z:y.second){
        //             cout<<x.first<< " "<< y.first<<" "<<z<<" "<<endl;
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> ans;
        while(left <= right){
            ans.push_back({});
            int lev = -1;
            int size = mp[left].size();
            while(size){
                lev++;
                if(mp[left].find(lev) == mp[left].end()) continue;
                sort(mp[left][lev].begin(), mp[left][lev].end());
                for(auto &x:mp[left][lev])
                    ans.back().push_back(x);
                size--;
            }
            left++;
        }
        return ans;
    }
};