class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //we have to find the weighted median
        int n = nums.size();
        vector<vector<int>> merge;
        double S = 0;
        for(int i = 0; i < n; i++){
            S += cost[i];
            merge.push_back({nums[i], cost[i]});
        }
        sort(merge.begin(), merge.end());
        int med = 0;
        double curr = 0;
        for(int i = 0; i < n; i++){
            curr += merge[i][1];
            med = merge[i][0];
            if(curr > S/2) break;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += abs(merge[i][0] - med) * merge[i][1];
        
        return ans;
    }
};