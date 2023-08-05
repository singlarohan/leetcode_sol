class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currMaj{}, freq{};
        for(int i = 0; i< nums.size(); i++){
            if(currMaj == nums[i])
                freq++;
            else if(freq == 0){
                currMaj = nums[i];
                freq = 1;
            }
            else
                freq--;
        }
        return currMaj;
    }
};