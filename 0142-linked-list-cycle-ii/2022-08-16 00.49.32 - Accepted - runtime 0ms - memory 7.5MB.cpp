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
        
        //https://www.youtube.com/watch?v=95ZfuoSAUPI
        //Floyd Warshell for 2nd part
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};