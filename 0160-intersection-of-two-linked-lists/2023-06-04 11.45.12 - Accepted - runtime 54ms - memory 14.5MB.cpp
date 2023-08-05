/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
        int n1{},n2{};
        while(curr1){
            curr1 = curr1 -> next;
            n1++;
        }
        while(curr2){
            curr2 = curr2 -> next;
            n2++;
        }
        curr1 = headA, curr2 = headB;
        while(n1 > n2){
            n1--;
            curr1 = curr1 -> next;
        }
        while(n1 < n2){
            n2--;
            curr2 = curr2 -> next;
        }
        while(curr1){
            if(curr1 == curr2) return curr1;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        return NULL;

    }
};