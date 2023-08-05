class Solution {
public:
    // if arr[0] = x, arr[1] = y
    // if first to be removed
    // arr[0] = y, arr[y] = y + i;
    // if second to be removed
    // arr[0] = x, arr[1] = x + i;
    int solve(int x, int i, int n, bool first){
        if(n / 2 == 0)
            return x;
        if(first || n % 2 != 0) x = x + i;
        return solve(x, i * 2, n/2, !first);
    }

    int lastRemaining(int n) {
        // vector<int> arr(2);
        // arr[0] = 1, arr[1] = 2;
        // int x = 1;
        return solve(1, 1, n, true);
    }
};