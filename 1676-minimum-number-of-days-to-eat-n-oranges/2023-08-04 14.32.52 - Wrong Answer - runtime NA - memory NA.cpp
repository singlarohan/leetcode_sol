class Solution {
public:
    unordered_map<int, int> mp;

    int solve(int n){
        if(n == 0) return 0;

        int ans = 0;
        
        if(n % 3 == 0) return 1 + solve(n / 3);

        else if((n - 1) % 3 == 0) return 1 + solve(n - 1);

        else if(n % 2 == 0) return 1 + solve(n / 2);

        else return 1 + solve(n - 1);
    }
    int minDays(int n) {
        return solve(n);
    }
};