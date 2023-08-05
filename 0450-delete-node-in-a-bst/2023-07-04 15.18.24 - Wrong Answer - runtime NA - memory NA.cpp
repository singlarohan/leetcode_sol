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
    TreeNode *rightnode(TreeNode *node){
        if(node -> right) return rightnode(node -> right);
        else if(node -> left) return rightnode(node -> left);
        else return node;
    }
    void solve(TreeNode *node, TreeNode *parent, int key){
        if(node == NULL) return;
        
        if(node -> val == key){
            if(node -> right == NULL){
                if(parent == NULL) head = node -> left;
                else parent -> left = node -> left;
            }
            else if(node -> right -> left == NULL){
                node -> right -> left = node -> left;
                if(parent == NULL) head = node -> right;
                else parent -> left = node -> right;
            }
            else{
                if(node -> left){
                    TreeNode *temp = rightnode(node -> left);
                    if(temp != NULL)
                        temp -> right = node -> right -> left;
                        node -> right -> left = node -> left;
                }

                if(parent == NULL) head = node -> right;
                else parent -> left = node -> right;
            }
        }
        
        else if(key > node -> val) solve(node -> right, node, key);

        else solve(node -> left, node, key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        head = root;
        solve(root, NULL, key);
        return head;
    }
};