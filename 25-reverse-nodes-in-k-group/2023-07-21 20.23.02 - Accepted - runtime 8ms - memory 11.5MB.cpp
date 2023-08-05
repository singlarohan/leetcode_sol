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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        int size = 0;
        while(curr){
            curr = curr -> next;
            size++;
        }

        int n = size / k;

        prev = NULL;
        curr = head;
        
        ListNode *curr_head, *prev_tail;

        bool flag = false;

        while(n--){
            int temp = k;
            
            curr_head = curr;
            prev_tail = prev;

            while(temp--){
                ListNode *temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
            }
            if(prev_tail) prev_tail -> next = prev;
            
            if(!flag) head = prev;
            
            curr_head -> next = curr;
            prev = curr_head;
            
            flag = true;
        }
        return head;
    }
};