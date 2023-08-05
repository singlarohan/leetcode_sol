class Solution {
public:
    int totalSteps(vector<int>& nums) {
        //Brute force simulation
        // bool flag{false};
        // int count{0};
        // while(1){
        //     int prev_val{-1};
        //     for(int i = 0; i < nums.size(); i++){
        //         if(nums[i] == INT_MAX)
        //             continue;
        //         int temp = nums[i];
        //         if(prev_val != -1 && prev_val > nums[i]) nums[i] = INT_MAX, flag = true;
        //         prev_val = temp;
        //     }
        //     if(flag) count++, flag = false;
        //     else break;
        // }
        // return count;

        //Linked List approach (okayish but poor space)
        // stack<int> s;
        // ListNode *head = new ListNode(nums[0]);
        // ListNode *curr = head;
        // for(int i = 1; i < nums.size(); i++)
        //     if(nums[i] <= curr -> val) curr -> next = new ListNode(nums[i]);
        int count{}, prev_val{nums[0]}, curr_count{0};
        for(int i = 1; i < nums.size(); i++){
            if(prev_val > nums[i]) curr_count++;
            else{
                prev_val = nums[i];
                count = max(count, curr_count);
                curr_count = 0;
            }
        }
        return count;
        
    }
};