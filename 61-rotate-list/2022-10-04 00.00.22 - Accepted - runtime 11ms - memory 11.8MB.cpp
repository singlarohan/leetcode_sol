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
        while(curr)
            n++, curr = curr -> next;
        k = k % n;
        if(k == 0)
            return head;
        curr = head;
        int i = n - k - 1;
        while(i--)
            curr = curr -> next;
        ListNode *head1 = curr -> next;
        curr -> next = NULL;
        curr = head1;
        while(curr -> next != NULL)
            curr = curr -> next;
        curr -> next = head;
        return head1;
    }
};