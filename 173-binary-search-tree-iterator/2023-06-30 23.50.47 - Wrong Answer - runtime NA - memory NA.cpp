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
class BSTIterator {
private:
    stack<TreeNode *> st;
    TreeNode *temp;
public:
    BSTIterator(TreeNode* root) {
        temp = root;
    }
    
    int next() {
        int ans{};
        while(!st.empty() || temp){
            if(temp){
                st.push(temp);
                temp = temp -> left;
            }
            else{
                if(ans != 0) return ans;
                temp = st.top();
                st.pop();
                ans = temp -> val;
                temp = temp -> right;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return temp || !st.empty();
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */