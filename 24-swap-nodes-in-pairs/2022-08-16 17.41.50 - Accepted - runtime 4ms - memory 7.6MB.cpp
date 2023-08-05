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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode *curr = head -> next -> next;
        ListNode *temp = head -> next;
        head -> next -> next = head;
        head -> next = curr;
        head = temp;
        curr = head -> next;
        
        while(curr -> next != NULL && curr -> next -> next != NULL){
            ListNode *temp1 = curr -> next -> next -> next;
            ListNode *temp2 = curr -> next;
            curr -> next = curr -> next -> next;
            curr -> next -> next = temp2;
            temp2 -> next = temp1;
            curr = curr -> next -> next;
        }
        return head;
    }
};