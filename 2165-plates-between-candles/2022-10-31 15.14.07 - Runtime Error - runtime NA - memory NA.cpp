class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> prefix(s.size(), 0);
        vector<int> bar;
        // unordered_map<int, int> prefix;
        int count{};
        int i{};
        while(s[i] == '*')
            i++;
        for(; i < s.size(); i++){
            if(s[i] == '|')
                prefix[i] = count, bar.push_back(i);
            else
                prefix[i] = prefix[i-1], count++;
        }
        // for(int i = 0; i < )
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            //search just larger than queries[i][0]
            int left = *upper_bound(bar.begin(), bar.end(), queries[i][0] - 1);
            if(left >= queries[i][1])
            ans.push_back(0);
            else
            ans.push_back(prefix[queries[i][1]] - prefix[left]);
        }
        //use binary search to find the nearest '|'
        //on both sides both left and right
        //then get the number of candles in that query
        return ans;
    }
};