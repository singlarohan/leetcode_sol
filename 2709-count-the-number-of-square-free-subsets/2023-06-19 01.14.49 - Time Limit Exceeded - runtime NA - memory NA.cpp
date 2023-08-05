class Solution {
public:
    bool check(long long n){
        for(long long i = 2; i * i <= n; i++)
            if(n % (i * i) == 0) return false;;
        return true;
    }

    int power(long long x, long long y, int p)
    {
    
        // Initialize answer
        int res = 1;
    
        // Check till the number becomes zero
        while (y > 0) {
    
            // If y is odd, multiply x with result
            if (y % 2 == 1)
                res = (res * x);
    
            // y = y/2
            y = y >> 1;
    
            // Change x to x^2
            x = (x * x);
        }
        return res % p;
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
        int req = (1 << n) - 1;

        for(int i = 1; i <= req; i++){
            long long cnt = 0, cnum = 1;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    if(cnt == 0) cnt = 1;
                    cnt *= temp[j].second;
                    cnt %= M;
                    cnum *= temp[j].first;
                    if(!check(cnum)){
                        cnt = 0;
                        break;
                    }
                }
            }
            ans = (ans + cnt) % M;
        }
        int temp1 = power(2,ones,M);
        ans *= temp1;
        ans += (1 << ones) - 1;
        ans %= M;
        return ans;
    }
};