class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg{};
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] < 0)
                neg++;
            else if(nums[i] == 0)
                return 0;
        if(neg % 2)
            return -1;
        return 1;
    }
};