class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int begin = nums[0];
        vector<string> ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] + 1 != nums[i]){
                ans.push_back("");
                if(begin != nums[i - 1])
                    ans.back() = to_string(begin) + "->" + to_string(nums[i - 1]);
                else ans.back() = to_string(begin);
                begin = nums[i];
            }
        }
        ans.push_back("");
        if(begin != nums.back())
            ans.back() = to_string(begin) + "->" + to_string(nums.back());
        else ans.back() = to_string(begin);
        return ans;
    }
};