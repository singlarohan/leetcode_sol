class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l{}, r = arr.size() - 1;
        int i{};
        while(i <= r){
            if(arr[i] == 0){
                swap(arr[i], arr[l]);
                if(i != l)
                i--;
                l++;
            }
            else if(arr[i] == 2){
                swap(arr[i], arr[r]);
                r--;
                i--;
            }
            i++;
        }
    }
};