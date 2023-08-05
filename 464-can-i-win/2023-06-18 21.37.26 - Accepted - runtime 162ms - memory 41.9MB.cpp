class Solution {
public:
    bool canIWin(int mci, int dtot) {
        //true =  1st player
        //false = 2nd player
        // int curr = 0;
        int sum = (mci*(mci + 1)) /2;
        if(sum < dtot) return false;
        if(sum == dtot) return mci % 2;
        // vector<vector<int>> dp(1 << mci, vector<int> (2, -1));
        vector<int> dp(1 << mci, -1);
        
        auto solve = [&](int mask, bool turn, int ctot, auto &&self){
            
            if(dp[mask] != -1) return dp[mask];

            if(turn){
                //even if one true we return true;
                for(int i = 0; i < mci; i++){
                    if((mask & (1 << i)) == 0){
                        if(ctot + (i + 1) >= dtot) 
                            return dp[mask] = true;
                        
                        if(self(mask | (1 << i), !turn, ctot + (i + 1), self)) 
                            return dp[mask] = true;
                    }
                }
            }
            else{
                //even if one false we return false;
                for(int i = 0; i < mci; i++){
                    if((mask & (1 << i)) == 0){
                        if(ctot + (i + 1) >= dtot) 
                            return dp[mask] = false;
                        
                        if(!self(mask | (1 << i), !turn, ctot + (i + 1), self)) 
                            return dp[mask] = false;
                    }
                }
            }
            return dp[mask] = !turn;
        };
        return solve(0, true, 0, solve);
    }
};