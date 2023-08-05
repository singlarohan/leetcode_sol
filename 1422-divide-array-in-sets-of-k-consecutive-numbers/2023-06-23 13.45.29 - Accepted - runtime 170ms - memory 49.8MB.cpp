class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(auto &x:nums) mp[x]++;
        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            while(mp.find(nums[i] + cnt) != mp.end() && cnt != k){
                mp[nums[i] + cnt]--;
                if(mp[nums[i] + cnt] == 0) mp.erase(nums[i] + cnt);
                cnt++;
            }
            if(cnt != 0 && cnt != k) return false;
        }
        return true;
    }
};