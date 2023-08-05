class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()- 1;
        int ans{};
        while(left < right){
            int lef_h = height[left];
            while(left < right && height[left] < height[right]){
                left++;
                lef_h = max(lef_h, height[left]);
                ans += lef_h - height[left];
            }
            int rig_h = height[right];
            while(left < right && height[left] >= height[right]){
                right--;
                rig_h = max(rig_h, height[right]);
                ans += rig_h - height[right];
            }
        }
        return ans;
    }
};