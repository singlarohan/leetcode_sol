class Solution {
public:
    int n, m, dp[1<<15];
    string t;
    vector<string> a;

    // mask of already matched words
    int rec(int mask)
    {
        // BC
        if (mask == (1<<m)-1) return 0;
        if (dp[mask] != -1) return dp[mask];

        int ans = 1e9;
        for (int i=0; i<n; i++)
        {
            vector<int> cnt(26, 0);
            // current sticker characters
            for (int j=0; j<a[i].size(); j++) cnt[a[i][j]-'a']++;

            int newmask = 0;
            for (int j=0; j<m; j++)
            {
                if (!((1<<j)&mask))
                {
                    // if jth letter is not present in the mask
                    // then set it if it's present in the cur sticker
                    if (cnt[t[j]-'a'] > 0)
                    {
                        cnt[t[j]-'a']--;
                        newmask |= (1<<j);
                    }
                }
            }
            // take this sticker only if it contributes anything
            // to the mask
            if (newmask != 0) ans = min(ans, 1+rec(mask|newmask));
        }
        return dp[mask] = ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        a = stickers;
        n = a.size(), m = target.size(); t = target;
        memset(dp, -1, sizeof dp);
        int ans = rec(0);
        if (ans >= 1e9) ans = -1;
        return ans;
    }
};