class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int total = accumulate(cookies.begin(), cookies.end(), 0);
        int target = total / k;
        // target += (total % k);
        vector<int> curr;
        auto solve = [&](int mask, auto &&self){
            if(mask == (1 << n) - 1) return *max_element(curr.begin(), curr.end());
            int ans = INT_MAX;
            if(curr.back() >= target && curr.size() != k){
                curr.push_back(0);
                ans = self(mask, self);
                curr.pop_back();
                return ans;
            }
            for(int i = 0; i < n; i++){
                if((mask & (1 << i)) == 0){
                    curr.back() += cookies[i];
                    ans = min(self((mask | (1 << i)), self), ans);
                    curr.back() -= cookies[i];
                }
            }
            return ans;
        };
        curr.push_back(0);
        return solve(0, solve);
    }
};