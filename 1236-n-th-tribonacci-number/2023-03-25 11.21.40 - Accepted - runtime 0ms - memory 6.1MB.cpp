class Solution {
public:
    int tribonacci(int n) {
        vector<int> prev = {0, 1, 1};
        if(n <= 2) return prev[n];
        for(int i = 3; i <= n; i++){
            // int temp = prev[0];
            prev = {prev[1], prev[2], prev[0] + prev[1] + prev[2]};
            // prev[0] = prev[1];
            // prev[1] = prev[2];
            // prev[2] = prev[0] + prev[1] + temp;
            // prev = curr;
        }
        return prev.back();
    }
};