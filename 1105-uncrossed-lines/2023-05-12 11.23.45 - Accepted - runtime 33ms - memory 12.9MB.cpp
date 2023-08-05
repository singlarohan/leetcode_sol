class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int, pair<vector<int>, int>> mp1;
        // unordered_map<int, pair<vector<int>, int>> mp2;
        // for(int i = 0; i < nums1.size(); i++){
        //     mp1[nums[i]].first.push_back(i);
        //     mp1[nums[i]].second = 0;
        // }
        // for(int i = 0; i < nums2.size(); i++){
        //     mp2[nums[i]].first.push_back(i);
        //     mp2[nums[i]].second = 0;
        // }
        
        //first without preprocessing optimization
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i >= m || j >= n) return 0;
            //if both are equal we always connect
            if(dp[i][j] != -1) return dp[i][j];
            if(nums1[i] == nums2[j]) return dp[i][j] = 1 + self(i + 1, j + 1, self);
            //else move i 1 forward and j 1 forward
            return dp[i][j] = max(self(i + 1, j, self), self(i, j + 1, self));
        };
        return solve(0, 0, solve);
    }
};