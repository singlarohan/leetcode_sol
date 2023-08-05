class Solution {
public:
    void solve(int i, string digits, vector<string> &ans, unordered_map<char, string> &mp, string s){
        if(i == digits.size())
            ans.push_back(s);
        for(int j = 0; j < mp[digits[i]].size(); j++){
            s.push_back((mp[digits[i]])[j]);
            solve(i + 1, digits, ans, mp, s);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        string s;
        solve(0, digits,ans,mp, s);
        return ans;
    }
};