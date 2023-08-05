class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < pow(2,n); i++){
            ans.push_back({});
            int temp = i;
            int count = 0;
            while(temp != 0){
                if(temp & 1) ans.back().push_back(nums[count]);
                count++;
                temp /= 2;
            }
        }
        return ans;
    }
};