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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev = list1, *last = list1;
        while(a - 1 || b + 1){
            if(a > 1){
                prev = prev -> next;
                a--;
            }
            if(b >= 0){
                last = last -> next;
                b--;
            }
        }
        prev -> next = list2;
        while(list2 -> next != NULL)
            list2 = list2 -> next;
        list2-> next = last;
        return list1;
    }
};