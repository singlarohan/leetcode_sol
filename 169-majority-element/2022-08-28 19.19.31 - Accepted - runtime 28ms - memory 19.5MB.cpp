class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num{}, occ{};
        for(auto &x:nums){
            if(num == x) occ++;
            else if(occ == 0){
                num = x;
                occ++;
            }
            else occ--;
        }
        return num;
    }
};