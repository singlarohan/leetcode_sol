/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node *> tq;
        if(!root)
            return ans;
        tq.push(root);
        while(!tq.empty()){
            int count = tq.size();
            ans.push_back({});
            while(count--){
                for(int i = 0; i < tq.front() -> children.size(); i++){
                    tq.push(tq.front() -> children[i]);
                }
                ans.back().push_back(tq.front() -> val);
                tq.pop();
            }
        }
        return ans;
    }
};