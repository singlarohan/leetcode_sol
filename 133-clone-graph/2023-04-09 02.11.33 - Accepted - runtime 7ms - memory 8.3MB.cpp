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
        unordered_map<int, Node*> vis;
        if(!node) return NULL;
        Node* head = new Node(node -> val);
        queue<pair<Node*, Node*>> q;
        q.push({head, node});
        vis[head -> val] = head;
        while(!q.empty()){
            Node *cop = q.front().first;
            Node *ref = q.front().second;
            q.pop();
            for(auto x: ref -> neighbors){
                if(vis.find(x -> val) == vis.end()){
                    Node *temp = new Node(x -> val);
                    vis[temp -> val] = temp;
                    q.push({temp, x});
                }
                (cop -> neighbors).push_back(vis[x -> val]);
            }
        }
        return head;
    }
};