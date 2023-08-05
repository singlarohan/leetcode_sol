class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& que) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i = 0; i < eq.size(); i++){
            mp[eq[i][0]].push_back({eq[i][1], values[i]});
            mp[eq[i][1]].push_back({eq[i][0], 1.0/values[i]});
        }
        // for(auto it: mp){
        //     cout<<it.first<<endl;
        //     for(auto i: it.second){
        //         cout<<i.first<<" "<<i.second<<endl;
        //     }
        // }

        unordered_set<string> vis;
        vector<double> ans(que.size(), -1.0);
        auto dfs = [&](string node, string &target, auto &&self) -> double{
            if(node == target) return 1.0;
            double an{-1.0};
            for(auto it:mp[node]){
                if(vis.find(it.first) == vis.end()){
                    // cout<<it.first<<" "<<it.second<<endl;
                    vis.insert(it.first);
                    an = max(an, it.second * self(it.first, target, self));
                }
            }
            // cout<<an<<endl;
            return an;
        };
        for(int i = 0; i < que.size(); i++){
            if(mp.find(que[i][0]) == mp.end()) continue;
            vis.insert(que[i][0]);
            double a = dfs(que[i][0], que[i][1], dfs);
            if(a >=0) ans[i] = a;
            vis.clear();
        }
        return ans;
    }
};