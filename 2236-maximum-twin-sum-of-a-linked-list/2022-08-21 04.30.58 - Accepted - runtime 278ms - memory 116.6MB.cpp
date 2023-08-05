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
    ListNode *reverse_list(ListNode *head){
        if(!head || !(head -> next))
            return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr){
            ListNode *temp = curr -> next;
            curr -> next = prev;
            prev = curr; 
            curr = temp;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode *slow, *mid = head, *fast = head;
        while(fast -> next && fast -> next -> next){
            mid = mid -> next;
            fast = fast -> next -> next;
        }
        //got mid half in left half of linked list
        mid -> next = reverse_list(mid -> next);
        int sum{INT_MIN};
        slow = head, fast = mid -> next;
        while(fast != NULL){
            sum = max(sum, fast -> val + slow -> val);
            fast = fast -> next; slow = slow -> next;
        }
        return sum;
    }
};