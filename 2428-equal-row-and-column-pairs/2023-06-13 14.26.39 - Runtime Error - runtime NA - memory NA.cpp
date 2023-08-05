class Solution {
public:
    struct VHasher {
        long long operator()(const vector<int> &V) const {
            long long hash = V.size();
            for(auto &i : V) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int, VHasher> mp;
        for(int i = 0; i < grid[0].size(); i++){
            vector<int> temp;
            for(int j = 0; j < grid.size(); j++)
                temp.push_back(grid[j][i]);
            mp[temp]++;
        }
        int ans{};
        for(int i = 0; i < grid.size(); i++)
            if(mp.find(grid[i]) != mp.end())
                ans += mp[grid[i]];
        return ans;
    }
};