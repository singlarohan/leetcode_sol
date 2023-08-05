class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi{};
        int curr{};
        for(auto x:gain){
            curr += x;
            maxi = max(curr, maxi);
        }
        return maxi;
    }
};