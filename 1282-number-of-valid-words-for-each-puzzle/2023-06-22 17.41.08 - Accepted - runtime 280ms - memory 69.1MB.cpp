class Solution {
private:
    unordered_map<int, int> mp;
public:
    int solve(int ind, int i, int mask, string &puz){
        if(i >= puz.size()) return 0;
        //not take
        int ans = solve(ind, i + 1, mask, puz);
        
        //take
        mask |= (1 << (puz[i] - 'a'));
        ans += solve(ind, i + 1, mask, puz);
        
        if(mp.find(mask) != mp.end())
        ans += mp[mask];

        return ans;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        //2 ^ 26 = 67108864

        int m = words.size(), n = puzzles.size();
        vector <int> ans(n, 0);
        for(int i = 0; i < m; i++){
            int mask = 0;
            for(auto c: words[i]) mask |= (1 << (c - 'a'));
            mp[mask]++;
        }
        for(int i = 0; i < n; i++){
            int mask = (1 << (puzzles[i][0] - 'a'));
            ans[i] += mp[mask];
            ans[i] += solve(i, 1, mask, puzzles[i]);
        }
        return ans;
    }
};