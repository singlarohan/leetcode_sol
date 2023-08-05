class Solution {

public:
    bool dp(vector<int>&nums,int currsum,int totalsum,int i,vector<int>d)
    {
        if(i>=nums.size())
        return false;
        if(currsum==totalsum)
        return true;
        if(d[totalsum]!=-1)
        return d[totalsum];

        bool take=dp(nums,currsum+nums[i],totalsum-nums[i],i+1,d);
        bool nottake=dp(nums,currsum,totalsum,i+1,d);

        return d[totalsum]= take or nottake;
    }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;

        for(int i=0;i<nums.size();i++)
        {
            totalsum+=nums[i];
        }
        int currsum=0;
        vector<int>d(totalsum + 1,-1);

        return dp(nums,currsum,totalsum,0,d);

    
        
    }
};