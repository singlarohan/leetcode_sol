/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*,TreeNode*> parentMap;
    void dfs(TreeNode* root,TreeNode *parent){
        if(root==NULL) return;

        parentMap[root] = parent;
        dfs(root->left,root);
        dfs(root->right,root);

        return;
    }

    unordered_map<TreeNode*, bool> vis;
    vector<int> ans;

    void findNodes(TreeNode* origin, int distance){

        if(origin==NULL || vis[origin])
            return;

        if(distance == 0){
            ans.push_back(origin -> val);
            return;
        }

        vis[origin]=true;
        
        findNodes(origin->left, distance - 1);
        findNodes(origin->right, distance - 1);
        findNodes(parentMap[origin], distance - 1);

        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,NULL);
        findNodes(target,k);

        return ans;
    }
};