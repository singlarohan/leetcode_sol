class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st, pq, tmp;

        for(int i = 0; i < nums.size(); i++){
            while(!pq.empty() && nums[pq.top()] < nums[i])
                ans[pq.top()] = nums[i], pq.pop();

            while(!st.empty() && nums[i] > nums[st.top()])
                tmp.push(st.top()), st.pop();
            //when popped once they will be reverse 
            //so we reverse again before inserting into pq
            //pq stored elements that have found one greater element
            while(!tmp.empty())
                pq.push(tmp.top()), tmp.pop();

            st.push(i);
        }
        return ans;
    }
};