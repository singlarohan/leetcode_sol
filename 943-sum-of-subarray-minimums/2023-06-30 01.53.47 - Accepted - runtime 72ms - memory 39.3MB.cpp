class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //N approach
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = arr.size(), M = 1e9 + 7;
        long long ans = 0;

        stack<int> st;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                int r = i;
                int mid = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                ans += (mid - l) * (long long)(r - mid) * arr[mid];
                ans %= M;
            }
            st.push(i);
        }
        return ans;
    }
};