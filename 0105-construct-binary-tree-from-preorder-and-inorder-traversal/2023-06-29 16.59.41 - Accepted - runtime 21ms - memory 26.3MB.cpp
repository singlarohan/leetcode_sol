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
public:
    TreeNode* solve(int istart, int iend, int pstart, int pend, 
                                    vector<int> &pre, vector<int> &ino){
        if(istart > iend || pstart > pend) return NULL;

        TreeNode *temp = new TreeNode(pre[pstart]);

        int ind = mp[pre[pstart]];
        int nleft = ind - istart;
        
        temp -> left = solve(istart, ind - 1, pstart + 1, pstart + nleft, pre, ino);
        temp -> right = solve(ind + 1, iend, pstart + nleft + 1, pend, pre, ino);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve(0, inorder.size() - 1, 0, preorder.size() - 1, preorder, inorder);
    }
};