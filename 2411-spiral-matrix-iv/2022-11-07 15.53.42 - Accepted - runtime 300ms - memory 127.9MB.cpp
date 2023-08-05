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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        // 0 -> right, 1 -> down, 2 -> left, 3 -> up
        int dir{};
        int i{}, j{};
        int l{-1}, u{0};
        while(head != NULL){
            if(dir == 0){
                if(j >= n) n--, i++, j--, dir = 1;
                else{
                    ans[i][j] = head -> val;
                    head = head -> next;
                    j++;
                }
            }
            else if(dir == 1){
                if(i >= m) m--, j--, i--, dir = 2;
                else{
                    ans[i][j] = head -> val;
                    head = head -> next;
                    i++;
                }
            }
            else if(dir == 2){
                if(j <= l) l++, i--, j++, dir = 3;
                else{
                    ans[i][j] = head -> val;
                    head = head -> next;
                    j--;
                }
            }
            else if(dir == 3){
                if(i <= u) u++, j++, i++, dir = 0;
                else{
                    ans[i][j] = head -> val;
                    head = head -> next;
                    i--;
                }
            }
        }
        return ans;
    }
};