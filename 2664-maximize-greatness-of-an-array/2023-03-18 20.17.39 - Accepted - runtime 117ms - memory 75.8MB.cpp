class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count{};
        int slow{}, fast{1};
        while(fast < nums.size()){
            if(nums[fast] > nums[slow]){
                slow++;
                count++;
            }
            fast++;
        }
        return count;
    }
};