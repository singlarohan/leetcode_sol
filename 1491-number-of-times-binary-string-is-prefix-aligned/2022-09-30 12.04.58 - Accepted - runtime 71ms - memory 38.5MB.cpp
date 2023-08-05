class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        // vector<bool> dp(flips.size(), false);
        // vector<bool> flipped(flips.size(), false);
        // auto check = [&](int i, auto && self){
        //     if(i == 0) return dp[0] = flipped[0];
        //     if(dp[i] != false) return dp[i];
        //     return dp[i] = flipped[i] && self(i - 1, self);
        // };
        // int count{};
        // for(int i = 0; i < flips.size(); i++){
        //     flipped[flips[i] - 1] = true;
        //     if(check(i, check))
        //         count++;
        // }
        // return count;
        //USING PRIORITY QUEUE
        // priority_queue<int> pq;
        // int count{};
        // for(int i = 0; i < flips.size(); i++){
        //     pq.push(flips[i]);
        //     if(i + 1 == pq.top()){
        //         count++;
        //         while(!pq.empty())
        //         pq.pop();
        //     }
        // }
        // return count;
        
        //BEST APPROACH
        long long curr{};
        int count{};
        for(int i = 0; i < flips.size(); i++){
            curr += flips[i] - 1;
            if(curr == ((long long)i*(i+1))/2)
            count++;
        }
        return count;
    }
};