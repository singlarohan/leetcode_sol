class Solution {
private:
    int n;
    vector<int> cookies;
public:
    int solve(int mask, int target, int num, int curr_sum){
        if(mask == (1 << n) - 1) return curr_sum;

        if(curr_sum >= target){
            if(num == 1) {
                for(int i = 0; i < cookies.size(); i++){
                    if((mask & (1 << i)) == 0){
                        curr_sum += cookies[i];
                    }
                }
                return curr_sum;
            }
            return max(curr_sum, solve(mask,((target * num) - curr_sum)/(num - 1), num-1, 0));
        }
        
        int ans = INT_MAX;

        for(int i = 0; i < cookies.size(); i++){
            if((mask & (1 << i)) == 0){
                ans = min(ans, solve(mask | (1 << i), target, num, curr_sum + cookies[i]));
            }
        }
        return ans;
    }

    int distributeCookies(vector<int>& coo, int k) {
        n = coo.size();
        int total = accumulate(coo.begin(), coo.end(), 0);
        cookies = coo;
        return solve(0, total/k + total % k, k, 0);
    }
};