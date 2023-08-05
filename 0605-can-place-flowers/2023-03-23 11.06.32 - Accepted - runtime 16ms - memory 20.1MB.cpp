class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        // bool flag{};
        int m = arr.size();
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0 && (!i || arr[i - 1] != 1) && (i == m - 1 || arr[i + 1] != 1))
                n--,i++;
        }
        return n <= 0;
    }
};