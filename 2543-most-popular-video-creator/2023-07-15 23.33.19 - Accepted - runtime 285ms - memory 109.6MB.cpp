class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, pair<long long, pair<int, int>>> mp;
        long long maxi = 0;
        for(int i = 0; i < ids.size(); i++){
            if(mp.count(creators[i])){
                mp[creators[i]].first += views[i];
                
                if(mp[creators[i]].second.first == views[i] && 
                                    ids[mp[creators[i]].second.second] > ids[i]) 
                    mp[creators[i]].second.second = i;
                
                else if(mp[creators[i]].second.first < views[i]) {
                    mp[creators[i]].second.first = views[i];
                    mp[creators[i]].second.second = i;
                }
            }
            else
                mp[creators[i]] = {views[i], {views[i], i}};
                
            maxi = max(mp[creators[i]].first, maxi);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            if(it.second.first == maxi)
                ans.push_back({it.first, ids[it.second.second.second]});
        }
        return ans;
    }
};