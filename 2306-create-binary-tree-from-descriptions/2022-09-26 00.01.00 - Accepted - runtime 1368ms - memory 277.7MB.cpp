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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode *> mp;
        unordered_map<int, bool> hasParent;
        
        for(int i = 0; i < descriptions.size(); i++){
            int temp = descriptions[i][0], temp1 = descriptions[i][1], temp2 = descriptions[i][2];
            if(mp.find(temp) == mp.end()){
                TreeNode *tempn = new TreeNode(temp);
                mp[temp] = tempn;
            }
            if(mp.find(temp1) == mp.end()){
                TreeNode *tempn = new TreeNode(temp1);
                mp[temp1] = tempn;
            }
            hasParent[temp1] = true;
            if(temp2)
                mp[temp] -> left = mp[temp1];
            else
                mp[temp] -> right = mp[temp1];
        }
        for(auto it:mp)
            if(hasParent.find(it.first) == hasParent.end())
                return it.second;
        return NULL;
    }
};