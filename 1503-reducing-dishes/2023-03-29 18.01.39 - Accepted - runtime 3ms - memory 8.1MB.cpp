class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(), sat.end());
        int total{}, curr{};
        for(int i = 0; i < sat.size(); i++){
            total += sat[i];
            curr += (i + 1) * sat[i];
        }
        int i{}, count{1};
        while(i < n && sat[i] < 0){
            total -= sat[i];
            if(curr < curr - count * sat[i] - total)
                curr = curr - count * sat[i] - total;
            else count++;
            i++;
        }
        return curr;
    }
};