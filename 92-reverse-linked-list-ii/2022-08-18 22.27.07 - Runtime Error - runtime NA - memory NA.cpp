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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        int i{1};
        ListNode *prev = head;
        while(i < left - 1){
            prev = prev -> next;
            i++;
        }
        ListNode *curr = prev;
        unordered_map<int, ListNode *> mp;
        while(i < right){
            curr = curr -> next;
            i++;
            mp[i] = curr; 
        }
        ListNode * temp = curr -> next;
        curr = prev;
        while(i >= left){
            curr -> next = mp[i];
            curr = curr -> next;
            i--;
        }
        curr -> next = temp;
        return head;
    }
};