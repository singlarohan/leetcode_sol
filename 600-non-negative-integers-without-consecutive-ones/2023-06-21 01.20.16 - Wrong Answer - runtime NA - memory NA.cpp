class Solution {
private:
    int m;
    vector<int> dp;
public:
    int solve(int i){
        if(i >= m) return 1;
        //if give 1 move 2 places forward
        //if give 0 move 1 place forward
        if(dp[i] != -1) return dp[i];
        // cout<<i<<endl;
        int ans = solve(i + 1) + solve(i + 2);
        return dp[i] = ans;
    }

    int findIntegers(int n) {
        m = log2(n) + 1;
        // cout<<m<<endl;
        //thing is  if our number is 10101100
        //agar left mein 1 hai toh consider hi nhi huey honge jo delete krne hain
        //toh chillax
        //then we need to subtract the subsets for
        //                            1000000 no need to subtract
        //                              10000 no need to subtract
        //                                 10 no need to subtract
        //                                 01 heavy need to subtract
        dp = vector<int> (m, -1);
        int ans = solve(0);
        // for(int i = 1; i < m; i++){
        //     if((n & (1 << (m - i))) == 0 && (n & (1 << (m - i + 1))) == 0){
        //         cout<<i<<endl;
        //         ans -= solve(i + 2);
        //     }
        // }
        //10011100011010
        return ans;
    }
};