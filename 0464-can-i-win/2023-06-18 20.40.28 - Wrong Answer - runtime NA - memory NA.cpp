class Solution {
public:
    bool canIWin(int mci, int dtot) {
        //true =  1st player
        //false = 2nd player
        // int curr = 0;
        vector<vector<int>> dp(1 << mci, vector<int> (2, -1));
        
        auto solve = [&](int mask, bool turn, int ctot, auto &&self){
            
            if(dp[mask][turn] != -1) return dp[mask][turn];

            if(turn){
                //even if one true we return true;
                for(int i = 0; i < mci; i++){
                    if((mask & (1 << i)) == 0){
                        if(ctot + (i + 1) >= dtot) 
                            return dp[mask][turn] = true;
                        
                        if(self(mask | (1 << i), !turn, ctot + (i + 1), self)) 
                            return dp[mask][turn] = true;
                    }
                }
            }
            else{
                //even if one false we return false;
                for(int i = 0; i < mci; i++){
                    if((mask & (1 << i)) == 0){
                        if(ctot + (i + 1) >= dtot) 
                            return dp[mask][turn] = false;
                        
                        if(!self(mask | (1 << i), !turn, ctot + (i + 1), self)) 
                            return dp[mask][turn] = false;
                    }
                }
            }
            return dp[mask][turn] = false;
        };
        return solve(0, true, 0, solve);
    }
};