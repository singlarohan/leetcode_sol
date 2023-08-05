class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //N^2 approach
        int n = arr.size();
        int M = 1e9 + 7;
        long long ans = 0;
        for(int i = 0; i < arr.size(); i++){
            int left{1};
            int right{1};
            //(left) * (right)
            int l = i - 1, r = i + 1;
            while(l >= 0 && arr[l] >= arr[i]) left++, l--;
            while(r < n && arr[r] > arr[i]) right++, r++;
            
            ans += ((long long)left)*(right)*arr[i];
            ans %= M;
        }
        return ans;
    }
};