/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<int,Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* temp = new Node(node -> val);
        mp[node -> val] = temp;
        while(!q.empty()){
            vector<Node*> nodes = q.front() -> neighbors;
            int val = q.front() -> val;
            q.pop();
            for(auto x:nodes){
                if(mp.find(x -> val) == mp.end()){
                    Node *t = new Node(x -> val);
                    mp[x -> val] = t;
                    q.push(x);
                }
                // cout<< val <<" "<< x -> val <<endl;
                mp[val] -> neighbors.push_back(mp[x -> val]);
                // cout<< val <<" "<< x -> val <<endl;
            }
        }
        return temp;
    }
};