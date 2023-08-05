class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans{};
        for(int i = 0; i < nums.size(); i++){
            int temp{}, count{};
            for(int j = 1; j < sqrt(nums[i]); j++){
                if(nums[i] % j == 0){
                    temp += j, count++;
                    if(j != nums[i] / j) {
                        temp += nums[i] / j;
                        count++;
                    }
                }
                if(count > 4) break;
            }
            if(count == 4) ans += temp;
        }
        return ans;
    }
};