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
    vector<string> ans;
public:
    void solve(string curr, TreeNode* root){
        if(!root) return;

        if(!(root -> left) && !(root -> right)){
            if(!curr.empty()) curr += "->";
            curr += to_string(root -> val);
            
            ans.push_back(curr);
            return;
        }
        if(!curr.empty()) curr += "->";
        curr += to_string(root -> val);
        
        solve(curr, root -> left);
        solve(curr, root -> right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root) solve("", root);
        return ans;
    }
};