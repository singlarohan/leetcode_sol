class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum{nums[0]};
        int ans{};
        int i{0}, j{1};

        while(j < nums.size()){
            if(k > sum){
                sum += nums[j];
                j++;
            }
            while(i< j && k <= sum){
                if(k == sum)
                ans++;
                sum -= nums[i];
                i++;
            }
        }
        if(k == sum)
            ans++;
        return ans;
    }
};