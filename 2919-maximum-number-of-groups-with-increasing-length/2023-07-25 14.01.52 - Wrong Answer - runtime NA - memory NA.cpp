class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int n = usageLimits.size();
        
        for(int i = n - 2; i >= 0; i--)
            usageLimits[i] = min(usageLimits.back(), ((n - 1) - i) + usageLimits[i]);
        
        
        return *min_element(usageLimits.begin(), usageLimits.end());
    }
};