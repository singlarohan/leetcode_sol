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
        // unordered_map<ListNode *, bool> mp;
        ListNode *slow = head, *fast = head;
        // while(curr != NULL){
        //     mp[curr] = true;
        //     curr = curr -> next;
        //     if(mp[curr])
        //         return curr;
        // }
        // return NULL;
        int i{1};
        while(fast != NULL && fast -> next != NULL){
            i++;
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                if(i % 2 == 0)
                    return slow -> next;
                else
                    return slow;
            }
        }
        return NULL;
    }
};