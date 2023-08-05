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
    ListNode *swap(ListNode *head){
        if(head -> next == NULL)
            return head;
        ListNode *temp1 = head -> next;
        ListNode *temp = head -> next -> next;
        head -> next -> next = head;
        head -> next = temp;
        return temp1;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head -> next))
            return head;
        ListNode *curr = head;
        head = swap(head);
        curr = head -> next;
        while(curr != NULL && curr -> next != NULL){
            ListNode *temp = curr -> next;
            curr -> next = swap(curr -> next);
            curr = temp;
        }
        return head;
    }
};