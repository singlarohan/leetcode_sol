class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = nums[0], cnt = 1;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0) x = nums[i], cnt = 1;
            else if(nums[i] == x) cnt++;
            else cnt--;
        }
        return x;
    }
};