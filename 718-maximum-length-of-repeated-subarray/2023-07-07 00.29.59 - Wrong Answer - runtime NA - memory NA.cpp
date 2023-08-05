class Solution {
private:
    int n1,n2;
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //using dp i will do this once again
        n1 = nums1.size(), n2 = nums2.size();
        vector<int> next(n2 + 1, 0);
        vector<int> prev(n2 + 1, 0);
        int ans = 0;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(nums1[i] == nums2[j])
                    next[j + 1] = 1 + prev[j];
                ans = max(ans, next[j + 1]);
            }
            prev = next;
        }
        return ans;
    }
};