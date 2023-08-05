class Solution {
private:
    unordered_map<char, int> mp;
public:
    string customSortString(string order, string s) {
        for(int i = 0; i < order.size(); i++)
            mp[order[i]] = i;
        sort(s.begin(), s.end(), [&](char a, char b){
            return mp[a] < mp[b];
        });
        return s;
    }
};