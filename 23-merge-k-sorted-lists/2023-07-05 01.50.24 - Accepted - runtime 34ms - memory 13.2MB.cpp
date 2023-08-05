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
        //comparing heads and adding to new linked lists with priority queue
        if(lists.size() == 0)
            return NULL;
        ListNode *head = new ListNode(5);
        ListNode *curr = head;
        priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0; i< lists.size(); i++){
            if(lists[i] != NULL)
            pq.push({lists[i] -> val, i});
        }
        while(!pq.empty()){
            pair<int, int> temp = pq.top();
            pq.pop();
            
            curr -> next = lists[temp.second];
            curr = curr -> next;
            
            lists[temp.second] = lists[temp.second] -> next;
            
            if(lists[temp.second]){
                temp.first = lists[temp.second] -> val;
                pq.push(temp);
            }

        }
        return head -> next;
    }
};