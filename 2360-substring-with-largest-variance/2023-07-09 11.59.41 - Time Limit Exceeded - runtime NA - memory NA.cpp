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
            unordered_map<int, int> cnt;
            int mini = INT_MAX;
            int maxi = 0;
            vector<int> curr(26, 0);
            for(int j = i; j < n; j++){    
                int temp = curr[s[j] - 'a'];
                if(temp != 0){
                    cnt[temp]--;
                    if(cnt[temp] == 0 && mini == temp) mini = mini + 1;
                }
                curr[s[j] - 'a']++;
                cnt[temp + 1]++;
                mini = min(mini, temp + 1);
                maxi = max(maxi, temp + 1);
                
                ans = max(maxi - mini, ans);
            }
        }
        return ans;
    }
};