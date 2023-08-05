class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> dp;
        while(n != 1){
            if(dp[n])
                return false;
            dp[n] = true;
            int num{};
            while(n != 0){
                num += pow(n%10, 2);
                n = n/10;
            }
            n = num;
        }
        return true;
    }
};