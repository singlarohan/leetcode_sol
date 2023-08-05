class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //we have to find the weighted median
        int n = nums.size();
        vector<int> idx(n);
        
        long long S = 0;
        for(int i = 0; i < n; i++){
            S += cost[i];
            idx[i] = i;
        }
        
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return nums[a] < nums[b];
        });
        
        int med = 0, i;
        
        double curr = 0;
        for(int k = 0; k < n; k++){
            i = idx[k];
            curr += cost[i];
            med = nums[i];
            if(curr > S/2.0) break;
        }

        long long ans = 0;
        for(int k = 0; k < n; k++){
            i = idx[k];
            ans += abs(nums[i] - med) * (long long)cost[i];
        }
        return ans;
    }
};