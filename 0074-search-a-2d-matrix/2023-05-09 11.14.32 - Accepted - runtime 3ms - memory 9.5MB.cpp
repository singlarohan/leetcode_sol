class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first column wise binary search and then row wise 
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1;
        int j = n - 1;
        while(up < down){
            int mid = up + (down - up)/2;
            if(matrix[mid][j] == target)
                return true;
            else if(matrix[mid][j] < target)
                up = mid + 1;
            else down = mid - 1;
        }
        if(matrix[up][j] < target) up++;
        if(up >= m) return false;
        cout<<up<<endl;
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right) /2;
            if(matrix[up][mid] == target) return true;
            else if(matrix[up][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
        // cout<<matrix[up][0]<<" "<<matrix[down][0]<<endl;
        // return matrix[up][0];
    }
};