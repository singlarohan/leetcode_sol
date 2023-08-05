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
    int minimumOperations(TreeNode* root) {
        //level order traversal and then 
        //find number of swaps for each level using
        //minimum no. of swaps algo
        queue<TreeNode*> q;
        q.push(root);
        int count{};
        while(!q.empty()){
            int n = q.size();
            vector<pair<int, int>> lev;
            while(n--){
                TreeNode * temp = q.front();
                q.pop();
                lev.push_back({temp -> val, lev.size()});
                if(temp -> left)
                q.push(temp -> left);
                if(temp -> right)
                q.push(temp -> right);
            }
            // for(auto x:lev)
            // cout<<x<<" ";
            // cout<<endl;
            sort(lev.begin(), lev.end());
            int i = 0;
            while(i < lev.size()){
                if(lev[i].second == i){
                    i++;
                    continue;
                }
                else{
                    swap(lev[i], lev[lev[i].second]);
                    i--;
                }
                count++;
                i++;
            }
        }
        return count;
    }
};