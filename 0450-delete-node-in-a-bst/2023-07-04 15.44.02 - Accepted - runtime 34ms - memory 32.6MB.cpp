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
    TreeNode *head;
public:
    TreeNode *leftnode(TreeNode *node){
        if(node -> left) return leftnode(node -> left);
        else return node;
    }
    void solve(TreeNode *node, TreeNode *parent, int key, int l){
        if(node == NULL) return;
        
        if(node -> val == key){
            if(node -> right == NULL){
                if(parent == NULL) head = node -> left;
                else if(l) parent -> left = node -> left;
                else parent -> right = node -> left;
                
                return;
            }
            else if(node -> right -> left == NULL)
                node -> right -> left = node -> left;
                
            else if(node -> left){
                    TreeNode *temp = leftnode(node -> right -> left);
                    temp -> left = node -> left;
                }

            if(parent == NULL) head = node -> right;
            else if(l) parent -> left = node -> right;
            else parent -> right = node -> right;
        }
        
        else if(key > node -> val) solve(node -> right, node, key, 0);

        else solve(node -> left, node, key, 1);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        head = root;
        solve(root, NULL, key, 0);
        return head;
    }
};