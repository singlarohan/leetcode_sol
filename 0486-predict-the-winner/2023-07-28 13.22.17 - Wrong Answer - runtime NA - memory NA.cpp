class Solution {
public:
    int solve(int l, int r, bool turn, vector<int> &nums){
        if(l > r) return 0;
        //turn variable is dependent in l and r so no need to memoise

        int ans;

        if(turn)
            //player 1 turn
            ans = max(nums[l] + solve(l + 1, r, !turn, nums), 
                          nums[r] + solve(l, r - 1, !turn, nums));
        
        else ans = min(-nums[l] + solve(l + 1, r, !turn, nums), 
                          -nums[r] + solve(l, r - 1, !turn, nums));

        return ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        return solve(0, nums.size() - 1, 1, nums) >= total / 2;
    }
};