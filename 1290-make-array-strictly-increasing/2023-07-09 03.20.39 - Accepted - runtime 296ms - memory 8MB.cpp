class Solution {
public:
    int findCeil(int target, int start, vector<int> &arr){
        int l = start, r = arr.size() - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r)/2;
            if(arr[mid] > target){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        
        vector<int> next(arr2.size() + 2, 0);
        vector<int> curr(arr2.size() + 2, 0);

        for(int i = arr1.size() - 1; i >= 0; i--){
            for(int j = arr2.size() - 1; j >= -1; j--){
                int ans = 1e9;
                int prev;

                if(j == -1) prev = i == 0 ? INT_MIN : arr1[i - 1];
                else prev = arr2[j];

                if(arr1[i] > prev)
                    ans = min(ans, next[0]);
                
                int ind = findCeil(prev, j + 1, arr2);
                if(ind != -1)
                    ans = min(ans, 1 + next[ind + 1]);
                
                curr[j + 1] = ans;
            }
            next = curr;
        }
        return curr[0] >= 1e8 ? -1 : curr[0];
    }
};