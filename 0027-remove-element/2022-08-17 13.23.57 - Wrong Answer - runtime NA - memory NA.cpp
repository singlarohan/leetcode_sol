class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l{0}, r = nums.size() - 1;
        int k = nums.size();
        while(l < r){
            while(nums[l] != val)
                l++;
            while(nums[r] == val){
                r--;
                k--;
            }
            if(nums[l] == val){
                swap(nums[l], nums[r]);
                l++;
                r--;
                k--;
            }
        }
        return k;
    }
};