class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> que;
        for(auto &x:queries) que.push_back({x, que.size()});
        
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        sort(que.begin(), que.end());
        // for(auto x:que) cout<<x.first<<" "<<x.second<<endl;
        unordered_map<int, int> mp;
        vector<int> ans(que.size());

        int l = 0, r = -1;

        for(int i = 0; i < que.size(); i++){
            int mini = que[i].first - x, maxi = que[i].first;
            if(i != 0 && que[i].first == que[i - 1].first){
                ans[que[i].second] = ans[que[i - 1].second];
                continue;
            }
            while(l < logs.size() && logs[l][1] < mini) {
                if(l <= r) {
                    mp[logs[l][0]]--;
                    if(mp[logs[l][0]] == 0) mp.erase(logs[l][0]);
                }
                l++;
            }
            if(l < logs.size()){
                if(r < l && logs[l][1] <= maxi) {
                    r = l;
                    mp[logs[r][0]]++;
                }

                while(r + 1 < logs.size() && logs[r + 1][1] <= maxi){
                    r++;
                    mp[logs[r][0]]++;
                }
            }
            // cout<<maxi<<" "<<l<<" "<<r<<endl;
            ans[que[i].second] = n - mp.size();
        }
        return ans;
    }
};