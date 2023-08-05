class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3,0);
        for(int i = 0; i<nums.size(); i++){
             count[nums[i]]++;   
        }
        for(int i = 0, j = 0; i<nums.size(); i++){
            while(count[j] == 0)
                j++;
            nums[i] = j;
            count[j]--;
        }
        return;
    }
};