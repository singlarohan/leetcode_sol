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
    ListNode *reverse_rec(ListNode *prev, ListNode *curr){
        if(!curr)
            return prev;
        ListNode *temp = curr -> next;
        curr -> next = prev;
        return reverse_rec(curr, temp);
    }
    //WITHOUT EXTRA SPACE
    void reorderList(ListNode* head) {        
        if(!head || !(head -> next))
        return;
        ListNode *slow = head, *fast = head;
        while(fast && (fast -> next))
        slow = slow -> next, fast = fast -> next -> next;
        ListNode *head2 = reverse_rec(slow, slow -> next);
        //making next of mid element NULL
        slow -> next = NULL;
        while(head != head2 && head -> next != head2){
            ListNode *temp = head -> next;
            head -> next = head2;
            head2 = head2 -> next;
            head -> next -> next = temp;
            head = temp;
        }
    }
};