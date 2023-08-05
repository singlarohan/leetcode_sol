class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int ans = -1;
        // int a = accumulate(gas.begin(), gas.end(), 0);
        // int b = accumulate(cost.begin(), cost.end(), 0);
        // if(b > a)
        //     return -1;
        for(int i = 0; i < gas.size(); i++){
            int prof{};
            if(gas[i] - cost[i] >= 0){
                for(int j = i; ; j = (j + 1) % gas.size()){
                    prof += gas[j] - cost[j];
                    if(prof < 0)
                        break;
                    if(j == (i - 1) % gas.size())
                        return i;
                }
            }
        }
        return -1;
    }
};