class Solution {
public:
    bool check (int n, int index, int S, int curr){
        long long ans{};
        int left = curr - (index + 1);
        ans += (long long)curr*curr; 

        if(index + 1 >= curr) ans += (index + 1 - curr);
        else ans -= ((long long)left*(left + 1)/2);

        int right = n - (index + 1);
        // ans += ((long long)(curr - 1) * (curr))/2;

        if(right + 1 > curr) ans += right + 1 - curr;
        else ans -= ((long long)(curr - 1 - right)*(curr - right))/2;

        return ans <= S;
    }

    int maxValue(int n, int index, int maxSum) {
        int ans{};
        int left = 1, right = maxSum;
        while(left <= right){
            int mid = (left + right)/2;
            if(check(n, index, maxSum, mid)){
                ans = max(ans, mid);
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};