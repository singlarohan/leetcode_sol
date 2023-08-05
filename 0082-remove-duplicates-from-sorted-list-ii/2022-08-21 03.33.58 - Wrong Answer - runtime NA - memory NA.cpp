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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode *prev = NULL, *curr = head, *succ = head -> next; 
        if(head -> next -> val != head -> val)
            prev = head, curr = head -> next, succ = head -> next -> next;
        while(succ != NULL){
            if(succ && succ -> val != curr -> val){
                prev = curr, curr = succ, succ = succ -> next;
                continue;
            }
            while(succ != NULL && succ -> val == curr -> val)
                succ = succ -> next;
            if(prev)
                prev -> next = succ;
            else if(!prev && succ && succ -> next && succ -> val != succ -> next -> val){
                prev = succ;
                head = succ;
                curr = succ -> next;
                succ = succ -> next;
            }
            curr = succ;
            if(succ)
            succ = succ -> next;
        }
        if(prev)
        return head;
        return prev;
    }
};