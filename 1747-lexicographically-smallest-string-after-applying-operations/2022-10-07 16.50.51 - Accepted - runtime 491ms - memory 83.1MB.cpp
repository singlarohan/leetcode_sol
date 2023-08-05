class Solution {
public:
    unordered_map<string, bool> mp;
    string ans;

    void solve(string s, int &a, int &b){
        if(mp.find(s) != mp.end())
        return;
        ans = min(ans, s);
        mp[s] = true;

        string temp = s;
        //rotating by b places
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        solve(s, a, b);
        
        //adding a 
        s = temp;
        for(int i = 1; i < s.size(); i += 2)
            s[i] = (s[i] - '0' + a) % 10 + '0';
        solve(s, a, b);
    }
    string findLexSmallestString(string s, int a, int b) {
        // two cases, b even, b odd
        // if b even even indices can't be changed
        //Trying with brute force (naive dfs/bfs)
        ans = "=";
        solve(s,a,b);
        return ans;
    }
};