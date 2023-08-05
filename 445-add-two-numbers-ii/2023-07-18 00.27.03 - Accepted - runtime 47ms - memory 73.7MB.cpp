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
    ListNode* reverse(ListNode *head)
    {
        // Initialize current, previous and next pointers
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> one;
        stack<int> two;
        while(l1){
            one.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2){
            two.push(l2 -> val);
            l2 = l2 -> next;
        }

        int carry = 0, temp;
        ListNode* head = NULL;
        ListNode* curr = head;

        while(!one.empty() || !two.empty() || carry){
            temp = carry;
            if(!one.empty()){
                temp += one.top();
                one.pop();
            }
            if(!two.empty()){
                temp += two.top();
                two.pop();
            }
            carry = temp / 10;
            temp = temp % 10;
            if(!head){
                head = new ListNode(temp);
                curr = head;
            }
            else{
                curr -> next = new ListNode(temp);
                curr = curr -> next;
            }
        }
        return reverse(head);
    }
};