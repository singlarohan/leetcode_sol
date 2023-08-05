class Solution {
private:
    vector<vector<int>> dp;
public:
    //true -> Alice
    //false -> Bob
    int solve(int i, int j, vector<int> &plates){
        if(i > j) return 0;
        int ans{};
        if(dp[i][j] != -1) return dp[i][j];

        bool turn = (plates.size() - (i + j)) % 2; 

        if(turn){
            ans = plates[i] + solve(i + 1, j, plates);
            ans = max(ans, plates[j] + solve(i, j - 1, plates));
        }
        else{
            ans = -plates[i] + solve(i + 1, j, plates);
            ans = min(ans, -plates[j] + solve(i, j - 1, plates));
        }
        return dp[i][j] = ans;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp = vector<vector<int>> (n, vector<int> (n, -1));
        int ans = solve(0, piles.size() - 1, piles);
        return ans > 0;
    }
};