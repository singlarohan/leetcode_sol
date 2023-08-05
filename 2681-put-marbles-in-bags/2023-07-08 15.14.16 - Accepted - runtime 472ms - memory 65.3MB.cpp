class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        //partition into k subarrays with minimum (max sum)
        //end + begin + (k - 1) partition indexes
        int n = weights.size();
        if(k == 1 || k == n) return 0;
        //cut at ndex 'j' costs = arr[j] + arr[j + 1];
        int curr = weights[0] + weights[n - 1];
        //we have to select k - 1 partitions
        priority_queue<int> mini;
        priority_queue<int, vector<int>, greater<int>> maxi;

        for(int i = 0; i < n - 1; i++) {
            maxi.push(weights[i] + weights[i + 1]);
            mini.push(weights[i] + weights[i + 1]);
            if(maxi.size() > k - 1) {
                maxi.pop();
                mini.pop();
            }
        }

        long long M = curr, m = curr;
        while(!maxi.empty()){
            M += maxi.top();
            maxi.pop();
            m += mini.top();
            mini.pop();
        }
        return M - m;
    }
};