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
            if(nums[i] - maxi.top().first > 2 || mini.top().first - nums[i] > 2){
                while(!maxi.empty()) maxi.pop();
                while(!mini.empty()) mini.pop();

            }
            while(1){
                bool flag{};
                while(!maxi.empty() && (maxi.top().first - nums[i] > 2 || maxi.top().second < l)){
                    l = max(maxi.top().second + 1, l);
                    maxi.pop();
                    flag = true;
                }
                while(!mini.empty() && (nums[i] - mini.top().first > 2 || mini.top().second < l)){
                    l = max(mini.top().second + 1, l);
                    mini.pop();
                    flag = true;
                }
                if(!flag) break;
            }
            
            if(maxi.empty()) l = i;
            
            maxi.push({nums[i], i});
            mini.push({nums[i], i});
            
            ans += (i - l + 1);    
        }
        return ans;
    }
};