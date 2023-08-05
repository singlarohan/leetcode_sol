class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans{};
        for(int i = 0; i < colors.size(); i++){
            int maxi = neededTime[i];
            ans += maxi;
            while(i < colors.size() - 1 && colors[i] == colors[i+1]){
                ans += neededTime[i+1];
                maxi = max(neededTime[i], neededTime[i+1]);
                i++;
            }
            ans -= maxi;
        }
        return ans;
    }
};