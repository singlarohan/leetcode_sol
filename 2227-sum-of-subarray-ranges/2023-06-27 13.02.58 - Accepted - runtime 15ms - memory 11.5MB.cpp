class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {

        int n=arr.size();

        vector<long long>dp(n,-1);
        vector<long long>cp(n,-1);

        stack<int>st;
        stack<int>stk;

       for (int i=0; i<n; i++)
        {
            while (!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if (!st.empty())
            {
                int j = st.top();
                dp[i] = dp[j] + (long long)arr[i]*(i-j);
            } 
            else dp[i] = (long long)arr[i]*(i+1);
            st.push(i);
        }

        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && arr[i]>=arr[stk.top()]) stk.pop();
            if (!stk.empty())
            {
                int j = stk.top();
                cp[i] = cp[j] + (long long)arr[i]*(i-j);
            } 
            else cp[i] = (long long)arr[i]*(i+1);
            stk.push(i);
        }

        long long res=0;

        for(int i=0;i<n;i++)
        {
            res+=cp[i]-dp[i];

        }

        return res;
        

        
    }
};