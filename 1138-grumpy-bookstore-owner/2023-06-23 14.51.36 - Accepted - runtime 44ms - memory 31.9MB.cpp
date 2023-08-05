class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int curr{};
        int n = customers.size();
        int ans{};
        for(int i = 0; i < k; i++){
            if(grumpy[i] == 1) curr += customers[i];
            else ans += customers[i];
        }
        
        int maxi = curr;

        for(int i = k; i < n; i++){
            if(grumpy[i - k]) curr -= customers[i - k];
            if(grumpy[i]) curr += customers[i];
            else ans += customers[i];
            maxi = max(curr, maxi);
        }
        return maxi + ans;
    }
};