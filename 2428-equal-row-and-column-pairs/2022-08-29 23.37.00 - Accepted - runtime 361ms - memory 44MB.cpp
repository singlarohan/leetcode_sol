class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> mp;
        for(int i = 0; i < grid.size(); i++){
            string temp= "";
            for(int j = 0; j < grid[0].size(); j++){
                temp += to_string(grid[i][j]);
                temp += " ";
            }
            mp[temp]++;
        }
        int ans{};
        for(int j = 0; j < grid[0].size(); j++){
            string temp = "";
            for(int i = 0; i< grid.size(); i++){
                temp += to_string(grid[i][j]);
                temp += " ";
            }
            ans += mp[temp];
        }
        return ans;
    }
};