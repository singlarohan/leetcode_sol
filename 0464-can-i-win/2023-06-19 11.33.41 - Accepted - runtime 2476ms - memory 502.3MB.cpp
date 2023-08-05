class Solution {
public:
    bool canIWin(int mci, int dtot) {
        //true =  1st player
        //false = 2nd player

        int sum = (mci*(mci + 1)) /2;
        
        if(sum < dtot) return false;
        if(sum == dtot) return mci % 2;

        vector<vector<int>> dp(1 << mci, vector<int> (2, -1));
        //we don't need 2d vector
        //because mask will always tell us whose turn it is
        //odd 1 bits = 2nd player's turn, even = 1st player's turn
        // vector<int> dp(1 << mci, -1);
        
        auto solve = [&](int mask, bool turn, int ctot, auto &&self){
            
            if(dp[mask][turn] != -1) return dp[mask][turn];
            
            for(int i = 0; i < mci; i++){
                if((mask & (1 << i)) == 0){
                    if(ctot + (i + 1) >= dtot || 
                      (!turn ^ self(mask | (1 << i), !turn, ctot + (i + 1), self))) 
                            return dp[mask][turn] = turn;
                }
            }

            return dp[mask][turn] = !turn;
        };
        return solve(0, true, 0, solve);
    }
};