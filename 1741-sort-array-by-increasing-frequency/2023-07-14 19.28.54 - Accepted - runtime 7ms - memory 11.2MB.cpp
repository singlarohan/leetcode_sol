class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
        
        auto comp = [](pair<int, int> &a, pair<int, int> &b){
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for(auto it:mp) pq.push({it.first, it.second});
        
        vector<int> ans;
        int k, a;
        while(!pq.empty()){
            k = pq.top().second;
            a = pq.top().first;
            while(k--)  ans.push_back(a);
            pq.pop();
        }
        return ans;
    }
};