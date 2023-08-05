class Solution {
public:
    bool check(vector<int> &arr, long long curr, int n){
        long long total = 0;
        for(auto &x:arr) total += min(curr, (long long)x);

        return total >= n * curr;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 1, right = 1e14 / n;
        long long ans = 1;

        while(left <= right){
            long long mid = (left + right) / 2;

            if(check(batteries, mid, n)){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};