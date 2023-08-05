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
    ListNode* rotateRight(ListNode* head, int k) {
        // ListNode *curr = head;
        // int n{};
        // if(!head || !(head-> next))
        //     return head;
        // while(curr)
        //     n++, curr = curr -> next;
        // k = k % n;
        // if(k == 0)
        //     return head;
        // curr = head;
        // k = n - k - 1;
        // while(k--)
        //     curr = curr -> next;
        // ListNode *head1 = curr -> next;
        // curr -> next = NULL;
        // curr = head1;
        // while(curr -> next != NULL)
        //     curr = curr -> next;
        // curr -> next = head;
        // return head1;
        
        //VDD   

        if(!k || !head || !(head-> next))
            return head;
        ListNode *p=head, *r=NULL;     
        int n{};
        while(p){
            p = p -> next;
            n++;
        }
        p = head;
        // cout<<n;
        k = k % n;

        deque<ListNode*> d;

        bool flag=false;

        while(p!=NULL){
            r=p;
            p=p->next;
            if(d.size()==k){
                ListNode* temp = d.front();
                if(p==NULL)
                    temp->next= NULL;
                d.pop_front();
                r->next=NULL;
            }
            d.push_back(r);
        }
        // while(!d.empty()){
        //     cout<<d.back() -> val<<endl;
        //     d.pop_back();
        // }

        while(!d.empty()){
            ListNode* temp = d.back();
            d.pop_back();
            // cout<<temp -> val<<endl;
            temp -> next = head;
            head=temp;
        }
        return head;
    }
};