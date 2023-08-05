class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int total = accumulate(cookies.begin(), cookies.end(), 0);
        // target += (total % k);
        // int target = total/k;
        vector<int> curr;
        auto solve = [&](int mask, int target, auto &&self){
            if(mask == (1 << n) - 1) return *max_element(curr.begin(), curr.end());
            int ans = INT_MAX;
            if(curr.back() >= target && curr.size() != k){
                int temp = (target *(k - curr.size() + 1) - curr.back()) / (k - curr.size());
                curr.push_back(0);
                ans = self(mask, temp,self);
                curr.pop_back();
                return ans;
            }
            for(int i = 0; i < n; i++){
                if((mask & (1 << i)) == 0){
                    curr.back() += cookies[i];
                    ans = min(self((mask | (1 << i)), target, self), ans);
                    curr.back() -= cookies[i];
                }
            }
            return ans;
        };
        curr.push_back(0);
        return solve(0, total/k, solve);
    }
};