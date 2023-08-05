class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        //using Bitmasking
        int m = requests.size(), ans = 0;
        
        vector<int> count(n, 0);

        for(int i = 0; i < (1 << m); i++){
            for(int j = 0; j < m; j++){
                if((i & (1 << j)) != 0){
                    ++count[requests[j][0]];
                    --count[requests[j][1]];
                }
            }
            bool flag{};
            for(auto &x:count){
                if(x != 0) flag = true;
                x = 0;
            }

            if(!flag) ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};