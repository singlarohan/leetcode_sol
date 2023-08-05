class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans{INT_MAX};
        for(int i = start; i < nums.size(); i++){
            if(target == nums[i]){
                ans = i - start;
                break;
            }
        }
        for(int i = start - 1; i >= 0; i--){
            if(target == nums[i]){
                ans = min(ans, start - i);
                break;
            }
        }
        return ans;
    }
};