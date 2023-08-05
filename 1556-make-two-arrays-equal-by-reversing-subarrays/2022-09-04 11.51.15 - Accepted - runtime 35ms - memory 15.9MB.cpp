class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]]++, mp[target[i]]--;
        for(auto it:mp)
            if(it.second != 0)
                return false;
        return true;
    }
};