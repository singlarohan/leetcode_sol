class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int eveSum{};
        vector<int> ans;
        for(auto &x:nums)
            if(x % 2 == 0)
                eveSum += x;
        for(int i = 0; i < queries.size(); i++){
            int j = queries[i][1];
            int a = queries[i][0];
            nums[j] += a;
            if((nums[j] - a) % 2 == 0){
                if(nums[j] % 2 == 0)
                    eveSum += a;
                else
                    eveSum -= (nums[i] - a);
            }
            else if(nums[i] % 2 == 0)
                    eveSum += nums[i];
            ans.push_back(eveSum);
        }
        return ans;
    }
};