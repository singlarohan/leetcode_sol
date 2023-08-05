class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size() - k;
        stack<int> s;
        for(int i = 0; i < nums.size(); i++){
            while(!s.empty() && n > 0 && nums[i] < s.top()){
                n--;
                s.pop();
            }
            s.push(nums[i]);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};