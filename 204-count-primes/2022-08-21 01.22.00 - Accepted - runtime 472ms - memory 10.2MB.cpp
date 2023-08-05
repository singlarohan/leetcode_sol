class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        vector<bool> v(n, true);
        v[0] = v[1] = false;
        unordered_map<double, bool> mp;
        for(double i = 2; i < sqrt(n); i++){
            if(!v[i])
                continue;
            for(double j = i*i; j < n; j+=i){
                if(!v[j])
                continue;
                v[j] = false;
            }
        }
        int count{};
        for(int i = 0; i<n; i++){
            if(v[i])
                count++;
        }
        return count;
    }
};