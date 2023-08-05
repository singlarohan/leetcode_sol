class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int ans{};
        for(int i = 0; i < n; i++){
            vector<int> cnt(n + 1, 0);
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