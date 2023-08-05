class Solution {
public:
    long long findScore(vector<int>& nums) {
        //using map
        // if(nums.size() == 1) return nums[0];
        // if(nums.size() == 2) return min(nums[0], nums[1]);
        set<pair<int,int>> st;
        long long ans{};
        for(int i = 0; i < nums.size(); i++) st.insert({nums[i], i});
            // if(mp[nums[i].first != 0])
        for(auto it:st){
            // cout<<it.first<<" "<<it.second<<endl;
            ans += it.first;
            int i = it.second;
            // if(i == nums.size() - 1){
            //     st.erase({nums[i - 1], i - 1});
            //     st.erase({nums[i - 2], i - 2});
            // }
            // else if(i == 0){
            //     st.erase({nums[i + 1], i + 1});
            //     st.erase({nums[i + 2], i + 2});
            // }
            // else{
            if(i + 1 < nums.size())
                st.erase({nums[i + 1], i + 1});
            if(i - 1 >= 0)
                st.erase({nums[i - 1], i - 1});
            st.erase(it);
            // }
        }
        return ans;
    }
};