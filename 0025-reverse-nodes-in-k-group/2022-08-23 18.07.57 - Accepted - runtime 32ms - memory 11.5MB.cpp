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
    ListNode *solve(ListNode *curr, ListNode *prev, int k){
        //we will return tail
        int i = k;
        ListNode* temp = curr;
        while(temp && i--)
            temp = temp -> next;
        if(i > 0)
            return curr;
        prev = reverse_list(curr, prev, k);
        //curr is now end
        curr -> next = solve(temp, curr, k);
        return prev;
    }
    
    ListNode *reverse_list(ListNode *curr, ListNode *prev, int i){
        //returns head of reversed_list
        if(i <= 0)
            return prev;
        ListNode *temp = curr -> next;
        curr -> next = prev;
        return reverse_list(temp, curr, i - 1);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        return solve(head, NULL, k);
    }
};