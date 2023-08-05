class Solution {
private:
    unordered_set<string> st;
public:
    vector<string> solve(int i, string &s){

        string temp = "";

        vector<string> ans;
        vector<string> curr;

        for(int j = i; j < s.size(); j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(j != s.size() - 1) {
                    curr = solve(j + 1, s);
                    for(auto &s:curr){
                        ans.push_back(temp + " " + s);
                    }
                }
                else
                    ans.push_back(temp);
            }
        }
        
        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto s:wordDict) st.insert(s);

        return solve(0, s);
    }
};