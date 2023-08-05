class Solution {
private:
    vector<vector<int>> dp;
public:
    int findCeil(int target, vector<int> &arr){
        int l = 0, r = arr.size() - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r)/2;
            if(arr[mid] > target){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }

    int solve(int i, int j, vector<int> &arr1, vector<int> &arr2){
        if(i >= arr1.size()) return 0;
        if(dp[i][j + 1] != -1) return dp[i][j + 1];

        int ans = 1e9;
        int prev;

        if(j == -1) prev = i == 0 ? INT_MIN : arr1[i - 1];
        else prev = arr2[j];

        if(arr1[i] > prev)
            ans = min(ans, solve(i + 1, -1, arr1, arr2));

        int ind = findCeil(prev, arr2);
        if(ind != -1) ans = min(ans, 1 + solve(i + 1, ind, arr1, arr2));

        return dp[i][j + 1] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        dp = vector<vector<int>> (arr1.size(), vector<int> (arr2.size() + 1, -1));
        sort(arr2.begin(), arr2.end());
        int ans = solve(0, -1, arr1, arr2);
        return ans >= 1e8 ? -1 : ans;
    }
};