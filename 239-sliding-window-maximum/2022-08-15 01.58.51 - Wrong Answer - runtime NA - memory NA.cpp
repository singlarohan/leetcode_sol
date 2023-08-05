class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int ans{}, ind{0};
        // for(int i = 0; i<k; i++){
        //     ans += nums[i];
        // }
        // int curr = ans;
        // for(int i = k; i< nums.size(); i++){
        //     curr += nums[i] - nums[i-k];
        //     if(curr > ans){
        //         ans = curr;
        //         ind = i - k + 1;
        //     }
        // }
        // vector<int> answ;
        // for(int i = ind; i < ind + k; i++)
        //     answ.push_back(nums[i]);
        // return answ;
        priority_queue<int> pq;
        for(int i = 0; i<k; i++){
            pq.push(nums[i]);
        }
        vector<int> ans;
        for(int i = k; i<nums.size(); i++){
            ans.push_back(pq.top());
            pq.push(nums[i]);
        }
        ans.push_back(pq.top());
        return ans;
    }
};