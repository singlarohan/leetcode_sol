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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head -> val == val)
            head = head -> next;
        if(!head || !head -> next)
            return head;
        ListNode *prev = head, *curr = head -> next;
        while(curr){
            if(curr -> val == val){
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else{
                prev = prev -> next;
                curr = curr -> next;
            }
        }
        return head;
    }
};