class Solution {
public:
    bool isValid(vector<int> &nums, int k, int maxi){
        int curr{}, count{1};
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            if(nums[i] > maxi) return false;
            if(curr > maxi){
                count++;
                curr = nums[i];
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        // cout<<right<<endl;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isValid(nums, k, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
        // return 0;
    }
};