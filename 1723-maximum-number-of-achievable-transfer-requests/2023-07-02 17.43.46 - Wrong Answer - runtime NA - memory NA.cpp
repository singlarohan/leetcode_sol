class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        //using Bitmasking
        int m = requests.size(), ans = 0;
        
        unordered_map<int, int> count;

        for(int i = 0; i < (1 << m); i++){
            for(int j = 0; j < m; j++){
                if((i & (1 << j)) != 0){
                    if(++count[requests[j][0]] == 0) count.erase(requests[j][0]);
                    if(--count[requests[j][1]] == 0) count.erase(requests[j][1]);
                }
            }
            if(count.empty()) ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};