class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 2; i >= 0; i--) st.push(nums[i]);

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(nums[i]);
        }
        return ans;

    }
};