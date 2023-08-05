class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();
        unordered_map<string, int> mp;
        vector<long long> dp(1 << m, -1);
        
        //mp maps indexes of all the skills
        for(int i = 0; i < m; i++) 
            mp[req_skills[i]] = i;
        
        vector<int> pskillmask(n, 0);
        //pskillmask is a mask containing the list of
        //skills for every person (if ith skill 'ith' bit is set)
        for (int i = 0; i < n; i++) 
            for (string &s : people[i]) 
                pskillmask[i] |= (1 << mp[s]);
        
        //pmask will contain the mask of which people are selected
        //and the function's job will be to minimize number of people
        //i.e. minimize the number of set bits in pmask
        
        //TABULATION
        //all skills are achieved no other person is needed
        // i.e. return 0; BASE CASE
        dp[(1 << m) - 1] = 0;

        for(int mask = (1 << m) - 2; mask >= 0; mask--){
            long long ans = INT_MAX;

            for(int i = 0; i < n; i++){
                int newMask = mask | pskillmask[i];
                //if newMask == mask, then we don't take
                //else take becomes person mask required from 
                //here on out after taking this
                if(newMask != mask){
                    long long take = ((long long) 1 << i) | dp[newMask];
                    if(__builtin_popcountll(take) < __builtin_popcountll(ans))
                        ans = take;
                }
            }
            dp[mask] = ans;
        }
        // long long pmask = solve(0);
        long long pmask = dp[0];
        
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if ((pmask >> i) & 1) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};