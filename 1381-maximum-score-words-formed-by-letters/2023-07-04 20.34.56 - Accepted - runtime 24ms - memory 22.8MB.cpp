class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int i, int mask, vector<string> &words, vector<char> &ltrs, 
                        vector<int> &scores, vector<int> &cnt){
        if(i >= words.size()) return 0;
        if(dp[mask][i] != -1) return dp[mask][i];
        int ans = solve(i + 1, mask, words, ltrs, scores, cnt);
        
        vector<int> curr_cnt = cnt;
        int curr{};
        
        for(int j = 0; j < words[i].size(); j++){
            curr_cnt[words[i][j] - 'a']--;
            curr += scores[words[i][j] - 'a'];

            if(curr_cnt[words[i][j] - 'a'] < 0) return ans;
        }
        ans = max(ans, curr +  solve(i + 1, mask | (1 << i), words, ltrs, scores, curr_cnt));
        return dp[mask][i] = ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> mp(26, 0);
        int n = words.size();
        
        dp = vector<vector<int>> (1 << n, vector<int> (n, -1));

        for(auto c:letters) mp[c - 'a']++;

        return solve(0, 0, words, letters, score, mp);
    }
};