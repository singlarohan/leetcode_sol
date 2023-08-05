class Solution {
public:
    bool binary_sear(vector<int> arr, int target){
        int begin = 0, end = arr.size() - 1;
        while(begin <= end){
            int mid = (begin + end)/2;
            if(arr[mid] == target)
                return true;
            else if(arr[mid] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int j = arr[0].size() - 1;
        int begin = 0, end = arr.size() - 1;
        while(begin < end){
            int mid = (begin + end)/2;
            if(arr[mid][j] == target)
                return true;
            else if(arr[mid][j] > target)
                end = mid - 1;
            else
                begin = mid + 1;
        }
        // if(arr[begin][j] == target)
        //     return true;
        if(arr[begin][j] < target)
            begin++;
        if(begin >= arr.size())
            return false;
        return binary_sear(arr[begin], target);
    }
};