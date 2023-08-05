class Solution {
public:
    int maxArea(vector<int>& height) {
        int lmax{}, rmax =height.size() - 1;
        int ans {INT_MIN};
        while(lmax<rmax){
            ans = max(ans, (rmax - lmax) * min(height[rmax], height[lmax]));
            if(height[lmax] > height[rmax])
                rmax--;
            else
                lmax++;
        }
        return ans;
    }
};