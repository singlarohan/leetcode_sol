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
        // int start = i;
        while(i < s.size()){
            if(s[i] == '*')
                curr++, add[i] = add[i-1];
            else
                add[i] = curr;
            i++;
        }
        i--, curr = add.back();
        while(i >= 0 && s[i] == '*')
            sub[i] = curr, i--;
        while(i >= 0){
            if(curr <= 0){
                sub[i--] = 0;
                continue;
            }
            if(s[i] == '*')
                curr--, sub[i] = sub[i + 1];
            else
                sub[i] = curr;
            i--;
        }
        for(int i = 0; i < s.size(); i++)
            cout<<add[i]<<" "<<sub[i]<<endl;
        for(int i = 0; i < queries.size(); i++){
            curr = add[queries[i][1]] - sub[queries[i][0]];
            ans.push_back(curr <= 0 ? 0 : curr);
        }
        return ans;
    }
};