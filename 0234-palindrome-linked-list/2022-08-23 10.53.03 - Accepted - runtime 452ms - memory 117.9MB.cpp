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
    ListNode *solve(ListNode* curr, ListNode *head){
        if(curr == NULL)
            return head;
        head = solve(curr -> next, head);
        if(!head)
            return NULL;
        if(curr -> val == head -> val){
            if(head -> next)    
            return head -> next;
            return head;
        }
        else
            return NULL;
    }
    
    ListNode *reverse_list(ListNode *head){
        if(!head || !(head -> next))
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode *temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        // vector<int> v;
        // while(head != NULL){
        //     v.push_back(head -> val);
        //     head = head -> next;
        // }
        // for(int i = 0; i < v.size()/2; i++){
        //     if(v[i] != v[v.size() - 1 - i])
        //         return false;
        // }
        // return true;
        
        //recursively
        
        // if(head == NULL)
        //     return head;
        // if(solve(head, head))
        //     return true;
        // return false;
        
        //finding mid, reverse the rest of the linked list
        ListNode *slow, *mid = head, *fast = head;
        while((fast -> next) && (fast -> next -> next)){
            mid = mid -> next;
            fast = fast -> next -> next;
        }
        mid -> next = reverse_list(mid -> next);
        slow = head, fast = mid -> next;
        while(fast != NULL){
            if(slow -> val != fast -> val)
                return false;
            slow = slow -> next, fast = fast -> next;
        }
        return true;
    }
};