class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mini;
        priority_queue<pair<int, int>> maxi;
        
        int l = 0;
        long long ans = 1;
        
        maxi.push({nums[0], 0});        
        mini.push({nums[0], 0});
        
        for(int i = 1; i < nums.size(); i++){
            auto  big = maxi.top();
            auto small = mini.top();
            if(nums[i] - big.first > 2 || small.first - nums[i] > 2){
                while(!maxi.empty()) maxi.pop();
                while(!mini.empty()) mini.pop();

            }
            bool ifchanged = false;
            while(1){
                bool flag{};
                while(!maxi.empty() && (maxi.top().first - nums[i] > 2 || (ifchanged && maxi.top().second < l))){
                    cout<<nums[i]<<" "<<maxi.top().first<<" "<<l<<" "<<maxi.top().second<<endl;
                    l = max(maxi.top().second + 1, l);
                    ifchanged = true;
                    maxi.pop();
                    flag = true;
                }
                while(!mini.empty() && (nums[i] - mini.top().first > 2 || (ifchanged && mini.top().second < l))){
                    cout<<nums[i]<<" "<<mini.top().first<<" "<<l<<" "<<mini.top().second<<endl;
                    l = max(mini.top().second + 1, l);
                    ifchanged = true;
                    mini.pop();
                    flag = true;
                }
                if(!flag) break;
            }
            // cout<<i<<" "<<maxi.size()<<" "<<l<<endl;
            if(maxi.empty()) l = i;
            
            maxi.push({nums[i], i});
            mini.push({nums[i], i});
            
            ans += (i - l + 1);    
        }
        return ans;
    }
};