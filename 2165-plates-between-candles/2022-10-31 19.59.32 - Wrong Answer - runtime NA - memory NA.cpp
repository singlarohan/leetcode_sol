class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        //using prefix sum
        //two arrays, one total sum, one to be subtracted
        vector<int> add(s.size(), 0), sub(s.size(), 0);
        vector<int> ans;
        int curr{};
        int i{};
        while(i < s.size() && s[i] != '|')
            i++;
        while(i < s.size()){
            if(s[i] == '*')
                curr++, add[i] = add[i-1];
            else
                add[i] = curr;
            i++;
        }
        while(--i >= 0 && s[i] == '*')
            sub[i] = curr;
        while(i >= 0){
            if(s[i] == '*')
                curr--, sub[i] = sub[i + 1];
            else
                sub[i] = curr;
            i--;
        }
        while(++i < queries.size()){
            ans.push_back(add[queries[i][1]] - sub[queries[i][0]]);
        }
        return ans;
    }
};