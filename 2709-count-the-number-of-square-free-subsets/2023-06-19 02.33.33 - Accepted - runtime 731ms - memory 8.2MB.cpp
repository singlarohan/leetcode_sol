class Solution {
public:
    bool check(long long n){
        for(long long i = 2; i * i <= 900; i++)
            if(n % (i * i) == 0) return false;;
        return true;
    }

    //for modular exponentiation
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
        //adding only those elements to map which are not 
        //already divisible by a square

        vector<pair<int, int>> temp;
        
        for(auto it:mp){
            if(it.first != 1)
                temp.push_back({it.first, it.second});
            //adding elements to temp array with their value and 
            //their frequency
        }

        int ones = mp[1], n = temp.size();
        //here ones stores the frequency of 1's on the 
        //it is being considered differently since we can take
        //any number of ones in a subset

        long long ans = 0;
        mp.clear();

        for(int i = 1; i <= (1 << n) - 1; i++){
            //cnt keeps current count of subsets
            //cnum keeps product of current subset
            //cnum will help us to determine where the
            //subset is viable or not            
            long long cnt = 0, cnum = 1;
            //after that we use bitmasking to generate
            //all possible subsets and find the number of those
            //subsets since the same integer can be repeated
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    if(cnt == 0) cnt = 1;
                    cnt *= temp[j].second;
                    cnt %= M;
                    cnum *= temp[j].first;
                    if(cnum > LONG_MAX / 30 && !check(cnum)){
                        //To avoid overflow additional check 
                        //has been placed
                        cnt = 0;
                        break;
                    }
                }
            }
            //to check if product of current subset is valid
            if(check(cnum))
            ans = (ans + cnt) % M;
        }
        //power stores the combinations of 1's
        //taking 0 '1', taking 1 '1', taking 2 '1'..... i.e.,
        //nC0 + nC1 + nC2......+ nCn = 2^n
        //here n = number of 1s = ones
        int power = powerMod(2,ones,M);
        //for all these combination of ones
        //we can multiply with eariler number of subsets 
        //without using 1s to get total number of subests
        ans *= power;
        //after that we add those subsets which have only 1s
        //similar to above while computing power
        //but here we don't need nC0 i.e. 0 '1' so
        //nC1 + nC2 + nC3 .... + nCn = 2^n - nC0 = 2^n - 1;
        //2^n is already computed
        ans += power - 1;
        
        ans %= M;

        return ans;
    }
};