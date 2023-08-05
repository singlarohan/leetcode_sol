class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++){
            if(i == 0 || nums[i-1] != nums[i]){
                for(int j = i+1; j< nums.size() - 2; j++){
                    if(j == i+1 || nums[j - 1] != nums[j]){
                        int left = j + 1;
                        int right = nums.size() - 1;
                        while(left < right){
                            double sum = (double)nums[left] + (double)nums[right] + (double)nums[i] + nums[j];
                            if(sum == target){
                                ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                                while(left < right && nums[left+1] == nums[left])
                                    left++;
                                while(left < right && nums[right] == nums[right - 1])
                                    right--;
                                left++, right--;
                            }
                            else if(target > sum){
                                while(left < right && nums[left+1] == nums[left])
                                    left++;
                                left++;
                            }
                            else{
                                while(left < right && nums[right] == nums[right - 1])
                                    right--;
                                right--;
                            }
                        }
                        // target += nums[j];
                    }
                }
                // target += nums[i];
            }
        }
        return ans;
    }
};