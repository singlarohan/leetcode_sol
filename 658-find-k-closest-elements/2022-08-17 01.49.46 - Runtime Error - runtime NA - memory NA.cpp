class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int close_ind{0};
        for(int i = 1; i < arr.size(); i++){
            if(abs(arr[i] - x) <= abs(arr[close_ind] - x))
                close_ind = i;
        }
        vector<int> ans;
        if(k == 0)
            return ans;
        ans.push_back(arr[close_ind]);
        int l{close_ind - 1}, r{close_ind + 1};
        while(ans.size() != k){
            if(abs(arr[l] - x) <= abs(arr[r] - x)){
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