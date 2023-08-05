class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1, n1{};
        int x2, n2{};
        for(int i = 0; i < nums.size(); i++){
            if(x1 == nums[i]) n1++;
            else if(x2 == nums[i]) n2++;
            else if(n1 == 0){
                x1 = nums[i];
                n1 = 1;
            }
            else if(n2 == 0){
                x2 = nums[i];
                n2 = 1;
            }
            else n2--, n1--;
        }
        n1 = 0, n2 = 0;
        //now we check if n1 and n2 do actually occur more than n/3 times or not
        for(auto x: nums){
            if(x1 == x) n1++;
            if(x2 == x) n2++;
        }
        vector<int> ans;
        if(n1 > nums.size()/3) ans.push_back(x1);
        if(n2 > nums.size()/3) ans.push_back(x2);
        return ans;
    }
};