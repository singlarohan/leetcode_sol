class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int prev = INT_MAX;
        int maxi = 0;
        int n = nums1.size();
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(max(nums1[i], nums2[i]) < prev){
                prev = min(nums1[i], nums2[i]);
                maxi = max(curr, maxi);
                curr = 1;
            }
            else{
                if(min(nums1[i], nums2[i]) >= prev) prev = min(nums1[i], nums2[i]);
                else prev = max(nums1[i], nums2[i]);
                curr++;
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};