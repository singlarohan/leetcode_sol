class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, vector<long long>> mp;
        long long maxi = 0;
        for(int i = 0; i < ids.size(); i++){
            if(mp.count(creators[i])){
                mp[creators[i]][0] += views[i];
                
                if(mp[creators[i]][1] == views[i] && ids[mp[creators[i]][2]] > ids[i]) 
                    mp[creators[i]][2] = i;
                
                else if(mp[creators[i]][1] < views[i]) {
                    mp[creators[i]][1] = views[i];
                    mp[creators[i]][2] = i;
                }
            }
            else
                mp[creators[i]] = {views[i], views[i], i};
            maxi = max(mp[creators[i]][0], maxi);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            if(it.second[0] == maxi)
                ans.push_back({it.first, ids[it.second[2]]});
        }
        return ans;
    }
};