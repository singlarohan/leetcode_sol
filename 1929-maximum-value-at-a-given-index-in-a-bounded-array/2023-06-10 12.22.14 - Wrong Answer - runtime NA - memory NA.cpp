class Solution {
public:
    bool check (int n, int index, int S, int curr){
        int ans{};
        int left = curr - (index + 1);
        ans += (curr*(curr + 1))/2;
        cout<<curr<<endl;
        if(index + 1 >= curr)
            ans += (index + 1 - curr);
        else
            ans -= (left*(left + 1)/2);
        cout<<ans<<" after:";
        //n - (index + 1)
        int right = n - (index + 1);
        ans += ((curr - 1) * (curr))/2;
        if(right + 1 > curr) ans += right + 1 - curr;
        else ans -= ((curr - 1 - right)*(curr - right))/2;
        //for 1232, index = 2, n = 4, right = 1, curr - 1 = 2
        cout<<ans<<" "<<endl;
        return ans <= S;
    }

    int maxValue(int n, int index, int maxSum) {
        int ans{};
        int left = 0, right = maxSum;
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