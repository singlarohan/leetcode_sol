/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *solve(ListNode* curr, ListNode *head){
        if(curr == NULL)
            return head;
        head = solve(curr -> next, head);
        if(!head)
            return NULL;
        if(curr -> val == head -> val){
            if(head -> next)    
            return head -> next;
            return head;
        }
        else
            return NULL;
    }
    
    bool isPalindrome(ListNode* head) {
        // vector<int> v;
        // while(head != NULL){
        //     v.push_back(head -> val);
        //     head = head -> next;
        // }
        // for(int i = 0; i < v.size()/2; i++){
        //     if(v[i] != v[v.size() - 1 - i])
        //         return false;
        // }
        // return true;
        if(head == NULL)
            return head;
        if(solve(head, head))
            return true;
        return false;
    }
};