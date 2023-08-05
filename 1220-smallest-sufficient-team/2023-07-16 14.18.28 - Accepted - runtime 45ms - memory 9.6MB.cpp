class Solution {
private:
    int m, n;
    unordered_map<string, int> mp;
    vector<int> pskillmask;
    vector<long long> dp;
public:

    long long solve(int mask){
        //all skills are achieved no other person is needed
        // i.e. return 0;
        if(mask == (1 << m) - 1) 
            return 0;

        if(dp[mask] != -1)
            return dp[mask];
            
        //if choose
        //mask gets updated

        for(int i = 0; i < n; i++){
                int newMask = mask | pskillmask[i];
                //if newMask == mask, then we don't take
                //else take becomes person mask required from 
                //here on out after taking this
                if(newMask != mask){
                    long long take = ((long long) 1 << i) | solve(newMask);
                    if(dp[mask] == -1 || 
                                __builtin_popcountll(take) < __builtin_popcountll(dp[mask]))
                        dp[mask] = take;
                }
        }
        //return the person mask with the  lease number of set bits
        //i.e. lease number of people
        return dp[mask];
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        m = req_skills.size();
        n = people.size();
        dp = vector<long long> (1 << m, -1);
        
        //mp maps indexes of all the skills
        for(int i = 0; i < m; i++) 
            mp[req_skills[i]] = i;
        
        pskillmask = vector<int> (n, 0);
        //pskillmask is a mask containing the list of
        //skills for every person (if ith skill 'ith' bit is set)
        for (int i = 0; i < n; i++) 
            for (string &s : people[i]) 
                pskillmask[i] |= (1 << mp[s]);
        
        //pmask will contain the mask of which people are selected
        //and the function's job will be to minimize number of people
        //i.e. minimize the number of set bits in pmask
        long long pmask = solve(0);

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if ((pmask >> i) & 1) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};