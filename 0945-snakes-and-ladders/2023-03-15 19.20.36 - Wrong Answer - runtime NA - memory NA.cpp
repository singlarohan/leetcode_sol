class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int tot = pow(n, 2);
        unordered_map<int, int> lad;
        unordered_set<int> snakes;
        vector<int> dp(tot + 1, 1e9);
        bool flag{true};
        int count{1};
        for(int i = n - 1; i >= 0; i--){
            if(flag) for(int j = 0; j < n; j++, count++){
                if(board[i][j] != -1){ 
                    if(board[i][j] > count)
                        lad[count] = board[i][j];
                    else snakes.insert(count);
                }
            }
            else{
                for(int j = n - 1; j >= 0; j--, count++)
                    if(board[i][j] != -1){ 
                        if(board[i][j] > count)
                            lad[count] = board[i][j];
                        else snakes.insert(count);
                    }
            }
            flag = !flag;
        }
        // for(auto it:lad)
        // cout<<it.first<<" "<<it.second<<endl;
        // for(auto it:snakes)
        // cout<<it<<endl;
        auto solve = [&](int curr, auto &&self) -> int{
            if(curr >= tot) return 0;
            // if(curr > tot) return 1e9;
            // if(curr > tot || snakes.find(curr) != snakes.end()) return 1e9;
            // if(lad.find(curr) != lad.end())
            //     return self(lad[curr]);
            if(dp[curr] != 1e9) return dp[curr];
            int ans = 1e9;
            // bool flag1{};
            for(int i = 6; i > 0; i--){
                if(snakes.find(curr + i) != snakes.end()) continue;
                if(lad.find(curr + i) != lad.end()){
                    ans = min(ans, self(lad[curr + i], self));
                    continue;
                }
                // if(!flag1)
                ans = min(ans, self(curr + i, self));
                // if(ans != 1e9)
                // flag1 = true;
            }
            return dp[curr] = min(dp[curr], 1 + ans);
        };
        int a = solve(1, solve);
        return a >= 1e9 ? -1 : a;
        // return 0;
    }
};