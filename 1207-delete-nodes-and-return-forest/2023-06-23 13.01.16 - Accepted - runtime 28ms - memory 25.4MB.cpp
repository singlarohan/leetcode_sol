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
    vector<TreeNode*> ans;
    unordered_set<int> todel;
public:
    TreeNode* dfs(TreeNode *root){
        if(!root) return NULL;
        bool flag = false;
        if(todel.find(root -> val) != todel.end()){
            flag = true;
            if(root -> left && todel.find(root -> left -> val) == todel.end())
                ans.push_back(root -> left);
            if(root -> right && todel.find(root -> right -> val) == todel.end())
                ans.push_back(root -> right);
        }
        root -> left = dfs(root -> left);
        root -> right = dfs(root -> right);
        return flag ? NULL : root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return ans;

        for(auto x:to_delete) todel.insert(x);

        if(todel.find(root -> val) == todel.end()) ans.push_back(root);

        dfs(root);
        return ans;
    }
};