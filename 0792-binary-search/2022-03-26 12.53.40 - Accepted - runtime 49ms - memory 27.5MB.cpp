class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        int lo=0, hi=n-1;
        
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            
            if(nums[mid]==t){
                return mid;
            }
            else if(nums[mid]>t){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return -1;
    }
};