class Solution {
public:
    int solve(int curr, int copd, int n){
        if(n == curr)
            return 0;
        int copy, paste;
        copy = paste = INT_MAX - 1000;
        //if copy and then paste
        if(2*curr <= n)
            copy = 2 + solve(curr + curr, curr, n);

        if(curr + copd <= n)
            paste = 1 + solve(curr + copd, copd, n);
        return min(copy, paste);
        
    }
    int minSteps(int n) {
        // if(n == 1)
        //     return 0;
        // return 1 + solve(1, 1, n);
        //Method 2
        int d = 2, ans = 0;
        while(n > 1){
            while(n % d == 0){
                ans += d;
                n = n/d;
            }
            d++;
        }
        return ans;
    }
};