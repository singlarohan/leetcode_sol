class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        //maxsum - minsum
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = arr.size();
        long long ans = 0;
        stack<int> st;
        stack<int> stk;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                int mid = st.top(), r = i;
                st.pop();
                int l = st.empty() ? -1 : st.top();
                ans -= (mid - l) * (r - mid) * (long long)arr[mid];
            }
            //subtracting when it is the minimum in the subarray
            while(!stk.empty() && (i == n || arr[stk.top()] <= arr[i])){
                int mid = stk.top(), r = i;
                stk.pop();
                int l = stk.empty() ? -1 : stk.top();
                ans += (mid - l) * (r - mid) * (long long)arr[mid];
            }
            //adding when it is the maximum in the subarray
            st.push(i);
            stk.push(i);
        }
        return ans;
    }
};