class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        int count{n-2};
        unordered_map<double, bool> mp;
        for(double i = 2; i < n; i++){
            if(mp[i])
                continue;
            for(double j = i*i; j < n; j+=i){
                if(mp[j])
                continue;
                count--;
                mp[j] = true;
            }
        }
        return count;
    }
};