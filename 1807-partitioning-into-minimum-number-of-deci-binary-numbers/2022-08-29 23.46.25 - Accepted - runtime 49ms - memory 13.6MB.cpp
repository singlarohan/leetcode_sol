class Solution {
public:
    int minPartitions(string n) {
        int maxi{INT_MIN};
        for(auto s: n)
            maxi = max(maxi, s - '0');
        return maxi;
    }
};