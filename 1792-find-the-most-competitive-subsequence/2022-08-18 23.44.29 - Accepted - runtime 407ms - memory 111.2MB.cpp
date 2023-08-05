class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size() - k;
        vector<int> s;
        for(int i = 0; i < nums.size(); i++){
            while(!s.empty() && n > 0 && nums[i] < s.back()){
                n--;
                s.pop_back();
            }
            s.push_back(nums[i]);
        }
        while(n > 0){
            s.pop_back();
            n--;
        }
        // vector<int> ans;
        // while(!s.empty()){
        //     ans.push_back(s.top());
        //     s.pop();
        // }
        // reverse(ans.begin(), ans.end());
        return s;
    }
};