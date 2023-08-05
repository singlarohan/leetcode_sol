class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<int> mp(26, 0);
        for(int i = 0; i < 3; i++)
            for(auto &c:rows[i])
                mp[c - 'a'] = i;
        
        vector<string> ans;
        for(auto &x:words){
            int curr = -1;
            bool flag = true;
            for(auto &y:x){
                if(curr == -1) curr = mp[tolower(y) - 'a'];
                else if(mp[tolower(y) - 'a'] != curr){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(x);
        }
        return ans;
    }
};