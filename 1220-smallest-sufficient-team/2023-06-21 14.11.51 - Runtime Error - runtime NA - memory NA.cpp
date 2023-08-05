class Solution {
private:
    int m, n;
    unordered_map<string, int> mp;
    unordered_map<int, unordered_map<int, long long>> dp;
public:
    int solve(int mask, int i, long long pmask, vector<string>& skills, vector<vector<string>>& people){
        if(mask == (1 << n) - 1) return pmask;
        if(i >= m) return 0;

        if(dp.find(mask) != dp.end() && dp[mask].find(i) != dp[mask].end())
            return dp[mask][i];
        //if choose
        int temp = mask;
        for(auto x: people[i]){
            if(mp.find(x) != mp.end() && (mask & (1 << mp[x])) == 0)
                mask = mask | (1 << mp[x]);
        }
        long long take = 0;
        if(mask != temp)
            take = solve(mask, i + 1, pmask | ( 1 << i), skills, people);

        //not take
        mask = temp;
        long long nottake = solve(mask, i + 1, pmask, skills, people);
        int a = __builtin_popcount(take);
        int b = __builtin_popcount(nottake);
        if(take == 0) return nottake;
        if(nottake == 0) return take;

        return a <= b ? take : nottake;

    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();
        for(int i = 0; i < n; i++) mp[req_skills[i]] = i;
        long long pmask = solve(0, 0, 0, req_skills, people);
        vector<int> ans;
        for(int i = 0; i < m; i++)
            if((pmask & (1 << i)) != 0) ans.push_back(i);
        
        return ans;
    }
};