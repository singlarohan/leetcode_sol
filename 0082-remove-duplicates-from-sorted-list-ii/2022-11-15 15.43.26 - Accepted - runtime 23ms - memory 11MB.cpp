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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next)
        return head;
        ListNode *prev = new ListNode(101);
        prev -> next = head;
        head = prev;
        ListNode *curr = prev -> next;
        ListNode *nex = curr -> next;
        while(nex){
            while(nex && curr -> val != nex -> val){
                prev = prev -> next;
                curr = curr -> next;
                nex = nex -> next;
            }
            if(!nex) break;
            while(nex && curr -> val == nex -> val)
                nex = nex -> next;
            prev -> next = nex;
            if(!nex) break;
            curr = nex;
            nex = nex -> next;
        }
        return head -> next;
    }
};