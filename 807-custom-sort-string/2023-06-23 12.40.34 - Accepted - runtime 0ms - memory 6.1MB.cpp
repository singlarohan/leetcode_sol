class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int, char> mp;
        for(int i = 0; i < order.size(); i++)
            mp[i] = order[i];
        
        unordered_map<char,int> cnt;
        for(auto c:s) cnt[c]++;

        int l = 0;
        for(int i = 0; i < 26; i++){
            if(mp.find(i) != mp.end()){
                while(cnt[mp[i]]--) s[l++] = mp[i];
                cnt.erase(mp[i]);
            }
        }
        for(auto &x:cnt){
            while(x.second--) s[l++] = x.first;
        }

        return s;
    }
};