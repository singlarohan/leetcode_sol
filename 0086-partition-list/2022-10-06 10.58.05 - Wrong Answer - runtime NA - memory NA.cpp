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
        if(!head || !(head -> next))
            return head;
        ListNode *temp = new ListNode(x - 1);
        temp -> next = head;
        head = temp;
        ListNode *prev, *curr = head;
        while(curr -> next && x > curr -> next -> val)
            curr = curr -> next;
        prev = curr;
        //currently stores
        while(curr -> next){
            while(curr -> next && x <= curr -> next -> val)
                curr = curr -> next;
            if(prev == head && head -> val >= x){
                ListNode *temp = curr -> next -> next;
                curr -> next -> next = prev;   
                // prev -> next = curr -> next;
                head = curr -> next;
                curr -> next = temp;
            }
            else{
                ListNode *temp = curr -> next -> next;
                //Now we transfer curr to after prev;
                curr -> next -> next = prev -> next;
                prev -> next = curr -> next;
                curr -> next = temp;
            }
        }
        return head -> next;
    }
};