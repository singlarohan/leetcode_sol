class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //N approach
        int n = arr.size(), M = 1e9 + 7;
        long long ans = 0;
        // vector<int> dp(n+1, 0); //it stores max elements in left of that element that can be 
                                //included in it's subarray
        stack<int> st;

        for(int i = 0; i <= arr.size(); i++){
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                // dp[i] += dp[st.top()];
                int r = i;
                int mid = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                ans += (mid - l)* (long long)(r - mid) * arr[mid];
                ans %= M;
            }
            st.push(i);
        }
        return ans;
    }
};