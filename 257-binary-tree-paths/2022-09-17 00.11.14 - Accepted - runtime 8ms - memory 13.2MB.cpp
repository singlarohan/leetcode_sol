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
    vector<string> ans;
    void solve(TreeNode *root, string temp){
        if(root == NULL)
            return;
        if(!root -> left && !root -> right){
            string temp1 = to_string(root -> val);
            temp += temp1;
            ans.push_back(temp);
            while(!temp1.empty()){
                temp.pop_back();
                temp1.pop_back();
            }
            return;
        }
        string temp1 = to_string(root -> val) + "->";
        temp += temp1;
        solve(root -> left, temp);
        solve(root -> right, temp);
        while(!temp1.empty()){
            temp.pop_back();
            temp1.pop_back();
        }
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        solve(root, temp);
        return ans;
    }
};