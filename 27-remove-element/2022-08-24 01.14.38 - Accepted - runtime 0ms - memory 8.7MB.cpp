class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // if(nums.size() == 1)
        //     return 0;
        int l{0}, r = nums.size() - 1;
        int k = nums.size();
        while(l <= r){
            if(nums[r] == val || nums[l] != val){
                while(r >= 0 && nums[r] == val){
                    r--;
                    k--;
                }
                while(l < nums.size() && nums[l] != val)
                    l++;
            }
            else{
                swap(nums[l], nums[r]);
                k--;
                l++;
                r--;
            }
        }
        return k;
    }
};