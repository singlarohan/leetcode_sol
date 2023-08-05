class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int close_ind = arr.size() - 1;
        for(int i = arr.size() - 2; i >= 0; i--){
            if(abs(arr[i] - x) <= abs(arr[close_ind] - x))
                close_ind = i;
        }
        vector<int> ans;
        if(k == 0)
            return ans;
        ans.push_back(arr[close_ind]);
        int l{close_ind - 1}, r{close_ind + 1};
        while(ans.size() != k){
            if(!(l < 0) && (r >= arr.size() || abs(arr[l] - x) <= abs(arr[r] - x))){
                ans.push_back(arr[l]);
                l--;
            }
            else{
                ans.push_back(arr[r]);
                r++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};