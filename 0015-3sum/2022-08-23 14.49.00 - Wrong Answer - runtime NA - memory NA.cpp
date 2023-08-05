class Solution {
public:
    // void solve(int i, vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums){
    //     if(i >= nums.size())
    //         return;
    //     if(temp.size() == 3){
    //         if(temp[0] + temp[1] + temp[2] == 0)
    //             ans.push_back(temp);
    //         else
    //             return;
    //     }
    //     //ifchoose
    //     temp.push_back(nums[i]);
    //     solve(i+1, ans, temp, nums);
    //     //else
    //     temp.pop_back();
    //     solve(i+1, ans, temp, nums);
    //     return;
    // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        // solve(0, ans, temp, nums);
        for(int i = 0; i< nums.size(); i++){
            temp.push_back(nums[i]);
            for(int j = nums.size() - 1; j >= 0; j--){
                temp.push_back(nums[j]);
                for(int k = j - 1; k > i; k--){
                    temp.push_back(nums[k]);
                    if((ans.empty() || temp != ans.back()) && nums[i] + nums[j] + nums[k] == 0)
                        ans.push_back(temp);
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }
        return ans;
    }
};