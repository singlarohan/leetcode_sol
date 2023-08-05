class Solution {
public:
    unordered_map<int, int> mp;
    int fact(int n){
        if(mp[n] != 0)
            return mp[n];
        return mp[n] = (n == 1 ? 1 : n * fact(n - 1));
    }

    int nPr(int n, int r){
        return fact(n) / fact(n - r);
    }


    int perm(int n, int r){
        if(r == 0)
            return 1;
        return n*perm(n-1, r-1);
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int ans{};
        for(int i = 0; i<n; i++){
            ans += nPr(9, i); 
        }
        // ans *= 9;
        return 9 * ans + 1;
    }
};