class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // vector<int> prefix(s.size(), 0);
        unordered_map<int, int> prefix;
        int i{};
        while(i < s.size() && s[i] == '*')
            i++;
        int count{};
        while(i < s.size()){
            if(s[i] == '*')
                count++;
            if(s[i] == '|')
                prefix[i] = count;
            i++;
        }
        vector<int> ans;
        // Binary search to process through queries
        for(int i = 0; i < queries.size(); i++){
            //we have to find first '|' on right of queries[i][0]
            //and first '|' on the left of queries[i][1]
            int left = INT_MAX, right = INT_MIN;
            for(auto it:prefix){
                if(it.first >= queries[i][0] && it.first <= queries[i][1]){
                    left = min(left, it.first);
                    right = max(right, it.first);
                }
            }
            ans.push_back(prefix[right] - prefix[left]);
        }
        return ans;
    }
};