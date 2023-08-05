class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        vector<vector<int>> mp(n);
        for(int i = 0; i < n; i++){
            if(i != 0) mp[i] = mp[i - 1];
            else mp[i] = vector<int> (26, 0);
            mp[i][s[i] - 'a']++;
        }
        int ans{};
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(int k = 0; k < 26; k++){
                    int curr = mp[j][k];
                    if(i != 0) curr -= mp[i - 1][k];
                    
                    if(curr == 0) continue;
                    mini = min(curr, mini);
                    maxi = max(curr, maxi);
                }
                ans = max(maxi - mini, ans);
            }
        }
        return ans;
    }
};