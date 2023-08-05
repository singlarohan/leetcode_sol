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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *, bool> mp;
        ListNode *curr = head;
        while(curr != NULL){
            mp[curr] = true;
            curr = curr -> next;
            if(mp[curr])
                return curr;
        }
        return NULL;
    }
};