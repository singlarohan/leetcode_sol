class Solution {
public:
    bool helper(int left, int right, vector<int> &piles, bool turn, vector<int> & count, vector<vector<int>> &dp){
        if(left > right){
            if(count[0] > count[1])
                return true;
            return false;
        }
        // if(dp[left][right] != -1)
        //     return dp[left][right];
        count[turn] += piles[right];
        bool end = helper(left, right - 1, piles, !turn, count, dp);
        count[turn] += piles[left] - piles[right];
        bool begin = helper(left, right - 1, piles, !turn, count, dp);
        count[turn] -= piles[left];
        return end || begin;
    }
    
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int> (piles.size(), -1));
        vector<int> count(2,0);
        return helper(0, piles.size() - 1, piles, 0, count, dp);
    }
};