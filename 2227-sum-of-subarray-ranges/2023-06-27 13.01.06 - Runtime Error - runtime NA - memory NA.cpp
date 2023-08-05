class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {

        int n=arr.size();

        vector<int>dp(n,-1);
        vector<int>cp(n,-1);

        stack<int>st;
        stack<int>stk;

       for (int i=0; i<n; i++)
        {
            while (!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if (!st.empty())
            {
                int j = st.top();
                dp[i] = dp[j] + arr[i]*(i-j);
            } 
            else dp[i] = arr[i]*(i+1);
            st.push(i);
        }

        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && arr[i]>=arr[stk.top()]) stk.pop();
            if (!stk.empty())
            {
                int j = stk.top();
                cp[i] = cp[j] + arr[i]*(i-j);
            } 
            else cp[i] = arr[i]*(i+1);
            stk.push(i);
        }

        int res=0;

        for(int i=0;i<n;i++)
        {
            res+=cp[i]-dp[i];

        }

        return res;
        

        
    }
};