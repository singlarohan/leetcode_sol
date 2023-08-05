class Solution {
private:
    int n;
    vector<int> dp;
public:
    int solve(int mask, vector<string> &words, vector<char> &ltrs, 
                        vector<int> &scores, vector<int> &cnt){
    
        // if(dp[mask] != -1) return dp[mask];
        
        vector<int> curr_cnt = cnt;
        int ans{};

        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) == 0){
                
                int curr = 0;
                bool flag = true;

                for(int j = 0; j < words[i].size(); j++){
                    
                    curr_cnt[words[i][j] - 'a']--;
                    curr += scores[words[i][j] - 'a'];
                    
                    //check if invalid i.e. used more characters
                    //than available
                    if(curr_cnt[words[i][j] - 'a'] < 0) {
                        flag = false;
                        break;
                    }
                }
                if(flag) 
                ans = max(ans, curr + solve(mask | 1 << i, words, ltrs, scores, curr_cnt));

                curr_cnt = cnt;
            }
        }
        // return dp[mask] = ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> mp(26, 0);
        n = words.size();
        
        dp = vector<int> (1 << n, -1);
        //mp stores total count of a letter in the letters array
        for(auto c:letters) mp[c - 'a']++;

        return solve(0, words, letters, score, mp);
    }
};