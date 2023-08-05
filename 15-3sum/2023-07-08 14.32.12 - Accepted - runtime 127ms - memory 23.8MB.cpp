class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<vector<int>> ans;

        for(int l = 0; l < n - 2; l++){
            if(l != 0 && arr[l] == arr[l - 1]) continue;
            int r = n - 1;
            for(int i = l + 1; i < r; i++){
                if(i != l + 1 && arr[i] == arr[i - 1]) continue;

                int curr = -(arr[i] + arr[l]);
                if(curr == arr[r]) ans.push_back({arr[l], arr[i], arr[r]});
                
                else if(curr < arr[r]) {
                    while(r > i && curr < arr[r])
                        r--;
                    i--;
                }
            }
        }
        return ans;
    }
};