class Solution {
public:
    int solve(int i,int j,int n,vector<int>& nums, int t,vector<vector<int>>&dp)
    {
        if(j==n-1)
        {
           long x=nums[j]-nums[i];
           if(x>=(-t) && x<=t)
           {   
               return 1;
           }
           return -1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
           int a=-1e9; 
           long k=nums[j]-nums[i];
           if(k>=(-t) && k<=t)
           {   
              a= 1 + solve(j,j+1,n,nums,t,dp);
           }
            
         int b = solve(i,j+1,n,nums,t,dp);
         
        return dp[i][j]=max(a,b);
        
    }
    int maximumJumps(vector<int>& nums, int t) 
    {
       int n=nums.size(),i=0,j=1,count=0;
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = solve(0,1,n,nums,t,dp);
        if(ans <= -1e8) return -1;
        return ans;
    }
};