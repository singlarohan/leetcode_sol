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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // //BRUTE FORCE
        // priority_queue<int, vector<int>, greater<int>> num;
        // for(int i = 0; i < lists.size(); i++){
        //     ListNode *curr = lists[i];
        //     while(curr != NULL){
        //         num.push(curr -> val);
        //         curr = curr -> next;
        //     }
        // }
        // ListNode *head = NULL;
        // if(!num.empty()){
        //     head = new ListNode(num.top());
        //     num.pop();
        //     ListNode *curr = head;
        //     while(!num.empty()){
        //         curr -> next = new ListNode(num.top());
        //         curr = curr -> next;
        //         num.pop();
        //     }
        // }
        // return head;
        
        //comparing heads and adding to new linked lists
        if(lists.size() == 0)
            return NULL;
        ListNode *head = new ListNode(5);
        ListNode *curr = head;
        while(1){         
            int mini = 0;
            for(int i = 1; i < lists.size(); i++){
                if(!lists[mini] || lists[i] && lists[mini] -> val > lists[i] -> val)
                    mini = i;
            }
            if(!lists[mini])
                break;
            curr -> next = new ListNode(lists[mini] -> val);
            curr = curr -> next;
            lists[mini] = lists[mini] -> next;
        }
        return head -> next;
    }
};