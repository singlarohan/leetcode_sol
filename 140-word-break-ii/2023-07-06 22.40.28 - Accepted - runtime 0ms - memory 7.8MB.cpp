class Solution {
private:
    unordered_set<string> st;
    vector<vector<string>> dp;
    vector<bool> vis;
public:
    vector<string> solve(int i, string &s){
        if(vis[i]) return dp[i];

        string temp = "";
        vector<string> ans;

        for(int j = i; j < s.size(); j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(j != s.size() - 1) {
                    vector<string> curr;
                    curr = solve(j + 1, s);
                    for(auto &s:curr){
                        ans.push_back(temp + " " + s);
                    }
                }
                else
                    ans.push_back(temp);
            }
        }
        vis[i] = 1;
        return dp[i] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto s:wordDict) st.insert(s);

        dp = vector<vector<string>> (s.size());
        vis = vector<bool> (s.size(), false);

        return solve(0, s);
    }
};