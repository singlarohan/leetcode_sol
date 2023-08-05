class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<vector<int>> ans;

        for(int l = 0; l < n - 2; l++){
            if(l != 0 && arr[l] == arr[l - 1]) continue;
            int i = l + 1, r = n - 1;
            while(i < r){
                if(i != l + 1 && arr[i] == arr[i - 1]){
                    i++;
                    continue;
                }

                int curr = -(arr[i] + arr[l]);
                if(curr == arr[r]) ans.push_back({arr[l], arr[i], arr[r]});
                
                if(curr >= arr[r]) i++;
                
                while(r > i && curr < arr[r]) r--;

            }
        }
        return ans;
    }
};