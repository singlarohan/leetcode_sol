class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> count;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;
        for(auto x:mp)
            if(count.find(x.second) != count.end())
                return false;
            else
            count.insert(x.second);
        return true;
    }
};