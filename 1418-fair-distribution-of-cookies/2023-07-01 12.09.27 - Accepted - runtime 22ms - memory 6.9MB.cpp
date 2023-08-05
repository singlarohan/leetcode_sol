class Solution {
private:
    int n;
    vector<int> cookies;
public:
    int solve(int mask, int target, int num, int curr_sum, vector<int> &coo){
        if(num == 1) {
            for(int i = 0; i < coo.size(); i++){
                if((mask & (1 << i)) == 0){
                    curr_sum += coo[i];
                }
            }
            return curr_sum;
        }

        if(curr_sum >= target){
            int next = ((target * num) - curr_sum)/(num - 1);
            return max(curr_sum, solve(mask,next, num-1, 0, coo));
        }
        
        int ans = INT_MAX;

        for(int i = 0; i < coo.size(); i++){
            if((mask & (1 << i)) == 0){
                ans = min(ans, solve(mask | (1 << i), target, num, curr_sum + coo[i], coo));
            }
        }
        return ans;
    }

    int distributeCookies(vector<int>& coo, int k) {
        n = coo.size();
        int total = accumulate(coo.begin(), coo.end(), 0);
        return solve(0, total/k, k, 0, coo);
    }
};