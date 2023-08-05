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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow, *prev = NULL;
        for(int i = 0; i<n; i++)
            fast = fast -> next;
        slow = head;
        while(fast != NULL){
            fast = fast -> next;
            prev = slow;
            slow = slow -> next;
        }
        if(prev == NULL)
            return head -> next;
        prev -> next = slow -> next;
        return head;
    }
};