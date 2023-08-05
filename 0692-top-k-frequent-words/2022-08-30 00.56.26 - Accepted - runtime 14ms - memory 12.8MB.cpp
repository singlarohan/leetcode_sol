class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        auto compare = [](const pair<int, string> &s1, const pair<int, string> &s2){ 
            if(s1.first == s2.first)
                return s1.second > s2.second;
            return s1.first < s2.first;
        }; 
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> pq(compare);
        for(auto s:words)
            mp[s]++;
        for(auto it:mp)
            pq.push({it.second, it.first});
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};