class Solution {
public:
    unordered_map<int, int> mp;

    int solve(int n){
        if(n == 0) return 0;

        if(mp.find(n) != mp.end()) return mp[n];

        // int ans = 1e9; 
        int a, b, c;
        a = b = c = 1e9;

        if(n % 3 == 0) a = solve(n / 3);
        if(n % 2 == 0) b = solve(n / 2);
        if((n - 2) % 3 == 0 || (n - 1) % 3 == 0 || (n - 1) % 2 == 0 || (a == 1e9 && b == 1e9))
        c = solve(n - 1);

        return mp[n] = 1 + min(a, min(b, c));
        // if(n % 3 == 0) {
        //     if(n % 2 == 0) ans = 1 + solve(n / 2);
        //     ans = min(ans, 1 + solve(n / 3));
        // }

        // else if(n % 2 == 0){
        //     if((n - 1) % 3 == 0) ans = 1 + solve(n - 1);
        //     ans = min(ans, 1 + solve(n / 2));
        // }

        // else ans = 1 + solve(n - 1);

        // return mp[n] = ans;
    }
    int minDays(int n) {
        return solve(n);
    }
};