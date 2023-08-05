class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans{INT_MAX - 100000};
        for(int i = 0; i < nums.size() - 2; i++){
            if(i == 0 || i > 0 && nums[i] != nums[i-1]){
                int left = i + 1;
                int right = nums.size() - 1;
                for(int right = nums.size() - 1; right - 1 > i; right--){
                    for(int left = i + 1; left < right; left++){
                        int temp = nums[i] + nums[left] + nums[right];
                        if(abs(target - ans) > abs(target - temp))
                            ans = temp;
                        while(left < right && nums[left + 1] == nums[left])
                            left++;
                    }
                    while(left < right && nums[right - 1] == nums[right])
                        right--;
                } 
            }
        }
        return ans;
    }
};