class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(26,0);
        for(int i = 0; i < order.size(); i++) mp[order[i] - 'a'] = i + 1;
        for(int i = 0; i < words.size() - 1; i++){
            int j{};
            int m = words[i].size(), n = words[i+1].size();
            while(j < m && j < n && mp[words[i][j] - 'a'] == mp[words[i + 1][j] - 'a'] ) j++;
            if(j == n && m > n) return false;
            if(j != m && j != n && mp[words[i][j] - 'a'] > mp[words[i+1][j] - 'a']) return false;
        }
        return true;
    }
};