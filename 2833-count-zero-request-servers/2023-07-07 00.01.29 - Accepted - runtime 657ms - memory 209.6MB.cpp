class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> que;
        for(auto &x:queries) que.push_back({x, que.size()});
        
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        sort(que.begin(), que.end());

        unordered_map<int, int> mp;
        vector<int> ans(que.size());

        int l = 0, r = -1;

        for(auto &it:que){
            int mini = it.first - x, maxi = it.first;
            int ind = it.second;

            while(l < logs.size() && logs[l][1] < mini) {
                if(l <= r) {
                    mp[logs[l][0]]--;
                    if(mp[logs[l][0]] == 0) mp.erase(logs[l][0]);
                }
                l++;
            }
            if(l < logs.size() && logs[l][1] <= maxi){
                if(r < l) {
                    r = l;
                    mp[logs[r][0]]++;
                }

                while(r + 1 < logs.size() && logs[r + 1][1] <= maxi){
                    r++;
                    mp[logs[r][0]]++;
                }
            }
            
            ans[ind] = n - mp.size();
        }
        return ans;
    }
};