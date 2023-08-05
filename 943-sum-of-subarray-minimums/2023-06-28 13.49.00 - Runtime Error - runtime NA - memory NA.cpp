class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //N^2 approach
        int n = arr.size(), ans = 0;
        for(int i = 0; i < arr.size(); i++){
            int left{1};
            int right{1};
            //(left) * (right)
            int l = i - 1, r = i + 1;
            while(l >= 0 && arr[l] >= arr[i]) left++, l--;
            while(r < n && arr[r] > arr[i]) right++, r++;
            ans += (left)*(right)*arr[i];
        }
        return ans;
    }
};