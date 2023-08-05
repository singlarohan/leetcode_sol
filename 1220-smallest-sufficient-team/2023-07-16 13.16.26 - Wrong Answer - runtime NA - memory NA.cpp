class Solution {
private:
    int m, n;
    unordered_map<string, int> mp;
    vector<int> pskillmask;
    vector<vector<long long>> dp;
public:

    long long solve(int mask, int i, long long pmask){
        if(mask == (1 << n) - 1) return pmask;

        if(i >= m) return LONG_MAX;

        if(dp[mask][i] != -1)
            return dp[mask][i];
            
        //if choose
        int newMask = mask | pskillmask[i];
        long long take = LONG_MAX;
        if(newMask != mask)
            take = solve(newMask, i + 1, pmask | ((long long) 1 << i));

        // not take
        long long nottake = solve(mask, i + 1, pmask);
        
        int a = __builtin_popcount(take);
        int b = __builtin_popcount(nottake);

        return dp[mask][i] = a <= b ? take : nottake;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();
        dp = vector<vector<long long>> (1 << n, vector<long long> (m, -1));
        
        //contains indexes of all the skills
        for(int i = 0; i < n; i++) mp[req_skills[i]] = i;
        
        pskillmask = vector<int> (m, 0);
        //pskillmask is a mask containing the list of
        //skills for every person (if ith skill 'ith' bit is set)
        for (int i = 0; i < m; i++) 
            for (string s : people[i]) 
                pskillmask[i] |= 1 << mp[s];
        
        //pmask will contain the mask of which people are selected
        //and the function's job will be to minimize number of people
        //i.e. minimize the number of set bits in pmask
        long long pmask = solve(0, 0, 0);

        vector<int> ans;

        for(int i = 0; i < m; i++)
            if((pmask & ((long long) 1 << i)) != 0) ans.push_back(i);
        
        return ans;
    }
};