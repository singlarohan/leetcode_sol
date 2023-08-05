class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans{INT_MIN};
        for(int i = start; i < nums.size(); i++){
            if(target == nums[i]){
                ans = i;
                break;
            }
        }
        for(int i = start - 1; i >= 0 && i >= 2*target - ans; i--){
            if(target == nums[i]){
                ans = i;
                break;
            }
        }
        return abs(ans - start);
    }
};