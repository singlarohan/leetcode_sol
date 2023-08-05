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
        unordered_map<int, int> mp;
        // solve(0, ans, temp, nums);
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i + 1;
        
        for(int i = 0; i < nums.size() - 2; i++){
            temp.push_back(nums[i]);
            for(int j = nums.size() - 1; j - 1 > i; j--){
                if(nums[j-1] < - nums[j] - nums[i])
                    break;
                temp.push_back(nums[j]);
                int k = mp[-(nums[i] + nums[j])] - 1;
                if(k>i){
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    temp.pop_back();
                }
                while(j - 1 > i && nums[j-1] == nums[j])
                    j--;
                temp.pop_back();
            }
            while(i < nums.size() - 2 && nums[i+1] == nums[i])
                i++;
            temp.pop_back();
        }
        return ans;
    }
};