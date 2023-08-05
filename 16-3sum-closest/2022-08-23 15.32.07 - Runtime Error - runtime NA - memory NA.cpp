class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans{INT_MAX};
        for(int i = 0; i < nums.size() - 2; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int temp = nums[i] + nums[left] + nums[right];
                if(abs(target - ans) > abs(target - temp))
                    ans = temp;
                while(left < right && nums[left + 1] == nums[left])
                    left++;
                while(left < right && nums[right - 1] == nums[right])
                    right--;
                left++;
                right--;
            }
            while(i < nums.size() - 2 && nums[i+1] == nums[i])
                i++;            
        }
        return ans;
    }
};