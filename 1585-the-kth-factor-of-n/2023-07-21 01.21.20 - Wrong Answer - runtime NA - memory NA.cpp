class Solution {
public:
    int kthFactor(int n, int k) {
        int total = 0;
        for(int i = 1; i <= sqrt(n); i++){
            if(n == i * (n / i)) {
                total += 2;
            }
        }
        total -= pow(2, (int)sqrt(n)) == n;
        int curr = 0;
        for(int i = 1; i <= sqrt(n); i++){
            if(n == i * (n / i)){
                curr++;
                if(curr == k) return i;
                if(total - curr + 1 == k) return n / i;
            }
        }
        return -1;
    }
};