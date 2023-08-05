/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        unordered_map<int, Node*> mp;
        Node *curr = head;
        while(curr != NULL){
            Node *temp = new Node(curr -> val);
            mp[temp -> val] = temp;
            curr = curr -> next;
        }
        curr = head;
        while(curr != NULL){
            if(curr -> random)
            mp[curr -> val] -> random = mp[curr -> random -> val];
            if(curr -> next)
            mp[curr -> val] -> next = mp[curr -> next -> val]; 
            curr = curr -> next;
        }
        return mp[head -> val];
    }
};