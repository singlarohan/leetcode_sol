class Solution {
public:
    int bulbSwitch(int n) {
        int k{}, odd{3};
        int ans{};
        while(k < n){
            k += odd;
            odd += 2;
            ans++;
        }
        return ans;
    }
};