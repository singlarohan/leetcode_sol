class Solution {
private:
    string ans = "";
    int n;
public:
    void solve(int i, string &s, string curr, string to_match, int K){
        //not take
        if(K == 0){
            if(ans.size() < to_match.size()) ans = to_match;
            else if(ans.size() == to_match.size()) ans = max(ans, to_match);
            return;
        }
        if(i >= n) return;

        solve(i + 1, s, curr, to_match, K);

        //assign current to to_match
        if(to_match.empty()) {
            solve(i + 1, s, "", curr + s[i], K - 1);
            solve(i + 1, s, curr + s[i], to_match, K);
        }

        else if(s[i] == to_match[curr.size()]){
            if(curr.size() == to_match.size() - 1){
                solve(i + 1, s, "", to_match, K - 1);
            }
            else
                solve(i + 1, s, curr + s[i], to_match, K);
        }
        return;

    }
    string longestSubsequenceRepeatedK(string s, int k) {
        n = s.size();
        solve(0, s, "", "", k);
        return ans;
    }
};