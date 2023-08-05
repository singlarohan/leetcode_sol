class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(int i = 0; i < knowledge.size(); i++)
            mp[knowledge[i][0]] = knowledge[i][1];
        string ans = "", temp = "";
        bool flag{true};
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') flag = false;
            else if(flag) ans += s[i];
            else if(s[i] == ')'){
                if(mp.find(temp) != mp.end())
                    ans += mp[temp];
                else ans += '?';
                temp = "";
                flag = true;
            }
            else temp += s[i];
        }
        return ans;
    }
};