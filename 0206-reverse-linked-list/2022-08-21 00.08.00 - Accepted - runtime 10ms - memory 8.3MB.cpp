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
    ListNode *reverse_rec(ListNode *prev, ListNode *curr){
        if(!curr)
            return prev;
        ListNode *temp = curr -> next;
        curr -> next = prev;
        return reverse_rec(curr, temp);
    }
    
    ListNode* reverseList(ListNode* head) {
        //recursively
        return reverse_rec(NULL, head);
        
        //Iteratively
        if(!head || !(head -> next))
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr != NULL){
            ListNode *temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};