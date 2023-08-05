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

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *curr = head;
        int n{};
        if(!head || !(head-> next))
            return head;
        while(curr){
            n++;
            curr = curr -> next;
        }
        k = k % n;
        if(k == 0)
            return head;
        ListNode *slow = head -> next, *fast = head -> next;
        for(int i = 0; i < n - k - 1; i++)
            fast = fast -> next;
        while(fast -> next)
            slow = slow -> next, fast = fast -> next;
        ListNode* head1 = slow -> next;
        fast -> next = head;
        slow -> next = NULL;
        return head1;
    }
};