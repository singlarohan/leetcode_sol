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
    bool ans = true;
    ListNode *solve(ListNode *head, ListNode *curr){
        if(curr == NULL) return head;
        ListNode *temp = solve(head, curr -> next);
        if(!temp) {
            ans = false;
            return temp;
        };
        if(curr -> val == temp -> val) return temp -> next;
        else return NULL;
    }

    bool isPalindrome(ListNode* head) {
        solve(head, head);
        return ans;
    }
};