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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int num1{0}, num2{0};
        ListNode *curr1 = l1, *curr2 = l2;
        // int n{0};
        // while(curr1 != NULL){
        //     num1 += pow(10,n) * curr1->val;
        //     num2 += pow(10,n) * curr2->val;
        //     curr1 = curr1-> next;
        //     curr2 = curr2 -> next;
        //     n++;
        // }
        // return num1 + num2;
        int carry{};
        ListNode *ans = new ListNode();
        ListNode *curr3 = ans;
        while(curr1 != NULL || curr2 != NULL){
            int temp{};
            if(curr1 != NULL){
                temp += curr1 -> val;
                curr1 = curr1-> next;
            }
            if(curr2 != NULL){
                temp += curr2 -> val;
                curr2 = curr2-> next;
            }
            curr3 -> val = (temp + carry) % 10;
            carry = (temp + carry)/10;
            if(curr1 != NULL || curr2 != NULL ){
                curr3 -> next = new ListNode();
                curr3 = curr3 -> next;
            }
        }
        if(carry != 0){
            curr3 -> next = new ListNode();
            curr3 -> next -> val = carry;
        }
        return ans;
    }
};