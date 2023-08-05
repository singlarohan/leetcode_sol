class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x1{}, n1{};
        int x2{}, n2{};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == x1 && n1) n1++;
            else if(nums[i] == x2 && n2) n2++;
            else if(n1 == 0){
                x1 = nums[i];
                n1 = 1;
            }
            else if(n2 == 0){
                x2 = nums[i];
                n2 = 1;
            }
            else n1--, n2--;
        }
        n1 = n2 = 0;
        for(auto &x:nums){
            if(x == x1) n1++;
            if(x == x2) n2++;
        }
        vector<int> ans;
        if(n1 > n/3) ans.push_back(x1);
        if(n2 > n/3 && x1 != x2) ans.push_back(x2);
        return ans;
    }
};