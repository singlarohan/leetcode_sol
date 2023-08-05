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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode* lodd = head;
        ListNode *curr = head -> next;
        ListNode *feven = head -> next;
        while(curr != NULL && curr -> next != NULL){
            lodd -> next = curr -> next;
            lodd = lodd -> next;
            ListNode *temp = lodd -> next;
            lodd -> next = feven;
            curr -> next = temp;
            curr = curr -> next;
        }
        return head;
    }
};