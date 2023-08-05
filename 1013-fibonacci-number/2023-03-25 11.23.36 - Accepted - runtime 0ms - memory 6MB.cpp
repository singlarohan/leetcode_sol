class Solution {
public:
    int fib(int n) {
        vector<int> prev = {0, 1};
        if(n <= 1) return prev[n];
        for(int i = 2; i <= n; i++){
            prev = {prev[1], prev[0] + prev[1]};
        }
        return prev.back();
    }
};