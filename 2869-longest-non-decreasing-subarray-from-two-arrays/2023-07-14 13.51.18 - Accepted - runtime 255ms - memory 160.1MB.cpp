class Solution {
public:
    int maxNonDecreasingLength(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        
        vector<int> curr(3, 0);
        vector<int> next(3, 0);
        
        for(int i = n - 1; i >= 0; i--){
            for(int prev = 0; prev <= 2; prev++){
                int last = !prev || !i ? INT_MIN : (prev == 1 ? arr1[i - 1] : arr2[i - 1]);
                
                int ans = 0;
                
                if(prev == 0) ans = next[0];

                if(arr1[i] >= last) ans = max(1 + next[1], ans);
                if(arr2[i] >= last) ans = max(1 + next[2], ans);

                curr[prev] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};