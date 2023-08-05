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
            curr_head = curr;
            prev_tail = prev;

            for(int i = 0; i < k; i++){
                ListNode *temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
            }            

            if(!flag){
                head = prev;
                flag = true;
            }

            if(prev_tail) prev_tail -> next = prev;

            curr_head -> next = curr;
            prev = curr_head;
        }
        return head;
    }
};