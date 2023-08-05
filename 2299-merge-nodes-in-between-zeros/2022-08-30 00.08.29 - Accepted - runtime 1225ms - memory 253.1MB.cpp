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
    ListNode *merge(ListNode *head){
        while(head -> next -> val != 0){
            head -> next -> val += head -> val;
            head = head -> next;
        }
        head -> next = head -> next -> next;
        return head;
    }
    
    ListNode* mergeNodes(ListNode* head) {
        head =  merge(head);
        ListNode *curr = head;
        while(curr -> next){
            curr -> next = merge(curr -> next);
            curr = curr -> next;
        }
        return head;
    }
};