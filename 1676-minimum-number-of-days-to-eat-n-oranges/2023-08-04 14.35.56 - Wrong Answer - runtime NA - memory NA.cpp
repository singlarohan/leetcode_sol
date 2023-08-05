class Solution {
public:
    unordered_map<int, int> mp;

    int solve(int n){
        if(n == 0) return 0;

        if(mp.find(n) != mp.end()) return mp[n];

        int ans = 1e9; 

        if(n % 3 == 0) ans = 1 + solve(n / 3);

        else if(n % 2 == 0){
            if((n - 1) % 3 == 0) ans = 1 + solve(n - 1);
            ans = min(ans, 1 + solve(n / 2));
        }

        else ans = 1 + solve(n - 1);

        return mp[n] = ans;
    }
    int minDays(int n) {
        return solve(n);
    }
};