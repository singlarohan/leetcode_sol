class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m != 0 || n != 0){
            if(n == 0 || nums1[m - 1] > nums2[n - 1]){
                m--;
                nums1[m + n] = nums1[m];
            }
            else{
                n--;
                nums1[m + n] = nums2[n];
            }
        }
        return;
    }
};