class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {    
        int n1{}, n2{};
        int o1{}, o2{};
        for(auto &x : nums){
            if(n1 == x) o1++;
            else if(n2 == x) o2++;
            else if(o1 == 0){
                n1 = x;
                o1++;
            }
            else if(o2 == 0){
                n2 = x;
                o2++;
            }
            else{
                o1--;
                o2--;
            }
        }
        vector<int> ans;
        o1 = 0, o2 = 0;
        for(auto &x:nums){
            if(x == n1)
                o1++;
            else if(x == n2)
                o2++;
        }
        if(o1 > floor(nums.size()/3))
            ans.push_back(n1);
        if(o2 > floor(nums.size()/3))
            ans.push_back(n2);
        return ans;
    }
};