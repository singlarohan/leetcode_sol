class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans{INT_MIN};
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int temp{};
            for(int j = 0; j < n; j++){
                temp += j*nums[(i+j) % n];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};