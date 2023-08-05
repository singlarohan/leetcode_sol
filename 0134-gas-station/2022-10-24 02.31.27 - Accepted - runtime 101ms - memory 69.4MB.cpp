class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int ans = -1;
        // int a = accumulate(gas.begin(), gas.end(), 0);
        // int b = accumulate(cost.begin(), cost.end(), 0);
        // if(b > a)
        //     return -1;
        int tot{};
        int prof{}, begin{0};
        for(int i = 0; i < gas.size(); i++){
            tot += gas[i] - cost[i];
            prof += gas[i] - cost[i];
            if(prof < 0){
                begin = i + 1;
                prof = 0;
            }
        }
        if(tot < 0)
            return -1;
        return begin;
    }
};