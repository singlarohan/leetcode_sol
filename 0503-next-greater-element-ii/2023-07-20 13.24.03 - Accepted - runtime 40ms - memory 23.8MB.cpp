class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MIN);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();

            ans[i] = st.empty() ? INT_MIN : st.top();

            st.push(nums[i]);
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();

            if(ans[i] == INT_MIN) ans[i] = st.empty() ? -1 : st.top();
        }
        return ans;
    }
};