class Solution {
public:
    //DONE IN O(log2(N) + k + k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int j = lower_bound(begin(arr), end(arr), x) - begin(arr);
        int i = j - 1;
        
        while (j - i - 1 < k) {
            if (i == -1 || (j < arr.size() && abs(arr[j] - x) < abs(arr[i] - x))) j++;
            else i--;
        }
        
        return vector<int>(begin(arr) + i + 1, begin(arr) + j);
    }
};