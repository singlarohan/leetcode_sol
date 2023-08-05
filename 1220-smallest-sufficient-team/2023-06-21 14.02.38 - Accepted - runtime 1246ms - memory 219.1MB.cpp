class Solution {
private:
    int m, n;
    unordered_map<string, int> mp;
    unordered_map<int, unordered_map<int, vector<int>>> dp;
public:
    vector<int> solve(int mask, int i, vector<string>& skills, vector<vector<string>>& people){
        if(mask == (1 << n) - 1) return {-1};
        if(i >= m) return {-2};
        if(dp.find(mask) != dp.end() && dp[mask].find(i) != dp[mask].end())
            return dp[mask][i];
        //if choose
        int temp = mask;
        for(auto x: people[i]){
            if(mp.find(x) != mp.end() && (mask & (1 << mp[x])) == 0)
                mask = mask | (1 << mp[x]);
        } 
        // cout<<i<<" "<<mask<<" "<<endl;
        vector<int> ans;
        vector<int> tv;
        if(mask != temp){
            ans.push_back(i);
            tv = solve(mask, i + 1, skills, people);
            if(tv.empty() || tv.back() == -2) ans.pop_back();
            else if(tv.back() != -1)
                for(auto x:tv) ans.push_back(x);
        }

        //not take
        mask = temp;
        tv = solve(mask, i + 1, skills, people);
        // for(auto x:ans) cout<<x<<" ";
        // cout<<endl;
        // for(auto x:tv) cout<<x<<" ";
        // cout<<endl;
        if(tv.empty() || tv.back() == -2) return dp[mask][i] = ans;
        if(ans.empty()) return dp[mask][i] = tv;
        return dp[mask][i] = ans.size() <= tv.size() ? ans : tv;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();
        for(int i = 0; i < n; i++) 
            mp[req_skills[i]] = i;
        return solve(0, 0, req_skills, people);
    }
};