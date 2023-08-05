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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *begin, *slow, *fast;
        begin = new ListNode(69);
        begin -> next = head;
        head = begin;
        begin = slow = fast = head;
        for(int i = 0; i < k - 1; i++){
            begin = begin -> next;
            fast = fast -> next;
        }
        while(fast -> next -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode *temp = slow -> next;
        slow -> next = begin -> next;
        fast = begin -> next -> next;
        begin -> next = temp;
        slow -> next -> next = temp -> next;
        temp -> next = fast;
        return head -> next;
    }
};