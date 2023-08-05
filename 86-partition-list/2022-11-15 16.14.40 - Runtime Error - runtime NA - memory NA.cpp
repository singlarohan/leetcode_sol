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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head -> next)
        return head;
        ListNode *head_first, *curr_first, *head_second, *curr_second;
        ListNode *curr = head;
        while(curr){
            if(curr -> val < x){
                if(!curr_first ) head_first = curr, curr_first = curr;
                else curr_first -> next = curr, curr_first = curr;
            }
            else{
                if(!curr_second) head_second = curr, curr_second = curr;
                else curr_second -> next = curr, curr_second = curr; 
            }
            curr = curr -> next;
        }
        if(!head_first) return head_second;
        curr_first -> next = head_second;
        return head_first;
    }
};