class Solution {
public:
    long long gcost(vector<int> & nums, vector<int> &cost, int med){
        long long ans{};
        for(int i = 0; i < nums.size(); i++)
            ans += (long long)(abs)(nums[i] - med) * cost[i];

        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        //using binary search
        long long ans = gcost(nums, cost, nums[0]);
        
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while(left <= right){
            int mid = (left + right) / 2;

            long long cost1 = gcost(nums, cost, mid);
            long long cost2 = gcost(nums, cost, mid + 1);
            ans = min(cost1, cost2);

            if(cost1 < cost2) right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }
};