class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> occ;
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto it:mp)
            occ.push_back(it.second);
        sort(occ.begin(), occ.end(), greater<>());
        int ans{occ[0]};
        int i = 1;
        for(i = 1; i < occ.size() && ans < arr.size()/2; i++)
            ans += occ[i];
        return i;
    }
};