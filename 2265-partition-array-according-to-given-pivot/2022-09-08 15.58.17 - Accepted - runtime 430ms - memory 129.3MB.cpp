class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        int count{};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > pivot)
                more.push_back(nums[i]);
            else if(nums[i] == pivot)
                count++;
            else
                less.push_back(nums[i]);
        }
        int i;
        for(i = 0; i < less.size(); i++)
            nums[i] = less[i];
        while(count--){
            nums[i] = pivot;
            i++;
        }
        for(int j = 0; j < more.size(); j++, i++)
            nums[i] = more[j];
        return nums;
    }
};