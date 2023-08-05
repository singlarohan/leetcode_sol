class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //N^2 approach
        int n = arr.size(), M = 1e9 + 7;
        long long ans = 0;
        vector<int> dp(n, 0);
        stack<int> st;

        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                dp[i] += dp[st.top()];
                int c = dp[st.top()] * arr[st.top()] * (long long)(i - st.top());
                ans += c;
                ans %= M;
                st.pop();
            }
            dp[i]++;
            st.push(i);
        }
        while(!st.empty()){
            int c = dp[st.top()] * arr[st.top()] * (long long)(n - st.top());
            ans += c;
            ans %= M;
            st.pop();
        }
        //dp[i] stores left
        return ans;
    }
};