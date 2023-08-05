class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        // WILL BE SOLVED BY USING TWO SLIDING WINDOWS
        //first we compute prefix sum
        vector<int> pref1(nums.size() - firstLen + 1, 0);
        vector<int> pref2(nums.size() - secondLen + 1, 0);
        int i = 0, curr{}; 
        while(i < firstLen){
            curr += nums[i];
            i++;
        }
        for(i = 0; i < nums.size() - firstLen; i++){
            pref1[i] = curr;
            curr += nums[i + firstLen] - nums[i];
        }
        pref1[i] = curr;
        i = 0, curr = 0;
        while(i < secondLen){
            curr += nums[i];
            i++;
        }
        for(i = 0; i < nums.size() - secondLen; i++){
            pref2[i] = curr;
            curr += nums[i + secondLen] - nums[i];
        }
        pref2[i] = curr;
        // for(auto &x:pref1) cout<<x<<" ";
        // cout<<endl;
        // for(auto &x:pref2) cout<<x<<" ";
        // cout<<endl;
        // for(int i = 0; i < )
        // pref2[i] = curr;    
        int ans{INT_MIN};
        for(int i = 0; i < nums.size() - firstLen; i++){
            for(int j = i + firstLen; j + secondLen <= i || j >= i + firstLen; j++){
                if(j + secondLen > nums.size()) {
                    j = -1;
                    continue;
                }
                ans = max(pref1[i] + pref2[j], ans);
                // cout<<i << " "<<j<<" "<<ans<<endl;
            }
        }
        return ans;
        //DP is UNINTUITIVE
        
    }
};