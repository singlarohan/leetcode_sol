class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool done{false};
        int count{1};
        for(int i = 1; i < nums.size(); i++){
            while(count <= i && nums[i] <= nums[i - count]){
                if(done) return false;
                else {
                    done = true;
                    count++;
                }
            }
            count = 1;
        }
        return true;
    }
};