class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans{};
        unordered_map<char, int> mp;
        for(int i = 0; i < garbage.size(); i++){
            for(int j = 0; j < garbage[i].size(); j++){
                while(mp[garbage[i][j]] != i){
                    ans += travel[mp[garbage[i][j]]];
                    mp[garbage[i][j]]++;
                }
                ans++;
            }
        }
        return ans;
    }
};