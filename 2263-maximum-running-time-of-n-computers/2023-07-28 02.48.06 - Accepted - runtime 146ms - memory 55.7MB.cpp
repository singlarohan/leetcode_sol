class Solution {
public:
    bool check(vector<int> &arr, long long curr, int n){
        int i = 0;
        while(i < arr.size() && n > 0 && arr[i] >= curr) i++, n--;

        long long rest = accumulate(arr.begin() + i, arr.end(), 0LL);

        n -= min((int)(rest / curr), (int)arr.size() - i);

        return n <= 0 ? true : false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end(), greater<int>());

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