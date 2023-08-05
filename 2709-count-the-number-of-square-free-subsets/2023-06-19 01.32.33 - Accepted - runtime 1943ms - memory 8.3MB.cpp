class Solution {
public:
    bool check(long long n){
        for(long long i = 2; i * i <= n; i++)
            if(n % (i * i) == 0) return false;;
        return true;
    }

    long long powerMod(long long base, long long exponent, long long modulus) {
        long long result = 1;
        base %= modulus;
        
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % modulus;
            }
            base = (base * base) % modulus;
            exponent >>= 1;
        }
        
        return result;
    }

    int squareFreeSubsets(vector<int>& nums) {
        //can't take a number twice in any subset
        //can't take a squared number
        //taken number must not be divisible by a square
        int M = 1e9 + 7;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++)
            if(check(nums[i])) mp[nums[i]]++; 
        
        vector<pair<int, int>> temp;
        
        for(auto it:mp){
            if(it.first != 1)
            temp.push_back({it.first, it.second});
        }
        
        int ones = mp[1], n = temp.size();
        long long ans = 0;
        mp.clear();
        
        for(int i = 1; i <= (1 << n) - 1; i++){
            long long cnt = 0, cnum = 1;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    if(cnt == 0) cnt = 1;
                    cnt *= temp[j].second;
                    cnt %= M;
                    cnum *= temp[j].first;
                    if(cnum > INT_MAX && !check(cnum)){
                        cnt = 0;
                        break;
                    }
                }
            }
            if(check(cnum))
            ans = (ans + cnt) % M;
        }
        ans = (powerMod(2,ones,M) * (ans + 1) - 1) % M;
        return ans;
    }
};