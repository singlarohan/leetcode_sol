class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> cand, ans;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '|')
                cand.push_back(i);
        for(int i = 0; i < queries.size(); i++){
            int left = lower_bound(cand.begin(), cand.end(), queries[i][0]) - cand.begin();
            int right = upper_bound(cand.begin(), cand.end(), queries[i][1]) - cand.begin() - 1;
            if(left >= right)
                ans.push_back(0);
            else
                ans.push_back(cand[right] - cand[left] - (right - left));
        }
        return ans;
    }
};