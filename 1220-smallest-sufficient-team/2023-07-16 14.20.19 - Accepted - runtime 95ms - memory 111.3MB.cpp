class Solution {
private:
    int m, n;
    unordered_map<string, int> mp;
    vector<int> pskillmask;
    vector<vector<long long>> dp;
public:

    long long solve(int mask, int i){
        //all skills are achieved no other person is needed
        // i.e. return 0;
        if(mask == (1 << n) - 1) return 0;

        if(i >= m) return INT_MAX;

        if(dp[mask][i] != -1)
            return dp[mask][i];
            
        //if choose
        //mask gets updated
        int newMask = mask | pskillmask[i];
        long long take = INT_MAX;
        
        //if newMask == mask, then we don't take
        //else take becomes person mask required from 
        //here on out after taking this
        if(newMask != mask)
            take = ((long long) 1 << i) | solve(newMask, i + 1);

        // not take
        long long nottake = solve(mask, i + 1);
        
        int a = __builtin_popcountll(take);
        int b = __builtin_popcountll(nottake);
        
        //return the person mask with the  lease number of set bits
        //i.e. lease number of people
        return dp[mask][i] = a <= b ? take : nottake;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();
        dp = vector<vector<long long>> (1 << n, vector<long long> (m, -1));
        
        //mp maps indexes of all the skills
        for(int i = 0; i < n; i++) 
            mp[req_skills[i]] = i;
        
        pskillmask = vector<int> (m, 0);
        //pskillmask is a mask containing the list of
        //skills for every person (if ith skill 'ith' bit is set)
        for (int i = 0; i < m; i++) 
            for (string &s : people[i]) 
                pskillmask[i] |= 1 << mp[s];
        
        //pmask will contain the mask of which people are selected
        //and the function's job will be to minimize number of people
        //i.e. minimize the number of set bits in pmask
        long long pmask = solve(0, 0);

        vector<int> ans;

        for(int i = 0; i < m; i++)
            if((pmask & ((long long) 1 << i)) != 0) ans.push_back(i);
        
        return ans;
    }
};