class Solution {
public:
    struct VectorHasher {
        int operator()(const vector<int> &V) const {
            long long hash = V.size();
            for(auto &i : V) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<vector<int>, int, VectorHasher> dp;
        auto solve = [&](int i, int prev, int d, auto && self) -> int{
            if(i >= nums.size())
                return 0;
            int ans{};
            if(dp.find({i, prev, d}) != dp.end())
                return dp[{i, prev, d}];
            for(int j = i; j < nums.size(); j++){
                if(prev == -1 || nums[j] - nums[prev] == d)
                    ans = max(ans, 1 + self(j + 1, j, d, self));
                else if(d == INT_MIN)
                    ans = max(ans, 1 + self(j + 1, j, nums[j] - nums[prev], self));
                // else if()
                //     ans = max(ans, 1 + self(j + 1, j, d, self));
            }
            return dp[{i, prev, d}] = ans;
        };
        return solve(0, -1, INT_MIN, solve);
    }
};