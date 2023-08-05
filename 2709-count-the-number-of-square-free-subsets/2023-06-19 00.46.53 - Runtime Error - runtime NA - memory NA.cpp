class Solution {
public:
    bool check(int n){
        for(int i = 2; i * i <= n; i++)
            if(n % (i * i) == 0) return false;;
        return true;
    }

    int squareFreeSubsets(vector<int>& nums) {
        //can't take a number twice in any subset
        //can't take a squared number
        //taken number must not be divisible by a square
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            if(check(nums[i])) mp[nums[i]]++; 
        vector<pair<int, int>> temp;
        for(auto it:mp){
            if(it.first != 1)
            temp.push_back({it.first, it.second});
        }
        for(auto x:temp) cout<<x.first<<" "<<x.second<<endl;
        int ones = mp[1];
        int n = temp.size();
        int ans{};
        int req = (1 << n) - 1;
        for(int i = 1; i <= req; i++){
            int cnt {}, cnum = 1;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    if(cnt == 0) cnt = 1;
                    cnt *= temp[j].second;
                    cnum *= temp[j].first;
                }
            }
            if(check(cnum))
            ans += cnt;
        }
        ans *= (1 << ones);
        ans += (1 << ones) - 1;

        return ans;
    }
};