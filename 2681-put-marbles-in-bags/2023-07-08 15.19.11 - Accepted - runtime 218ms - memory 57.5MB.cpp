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

        for(int i = 0; i < n - 1; i++) 
            weights[i] = weights[i] + weights[i + 1];
        
        weights[n - 1] = INT_MAX;        

        sort(weights.begin(), weights.end());

        long long M = curr, m = curr;
        for(int i = 0; i < n - 1 && i < k - 1; i++){
            m += weights[i];
            M += weights[n - 2 - i];
        }

        return M - m;
    }
};