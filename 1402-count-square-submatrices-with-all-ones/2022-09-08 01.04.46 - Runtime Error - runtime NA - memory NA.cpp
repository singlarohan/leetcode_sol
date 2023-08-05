class Solution {
public:
    int check(vector<vector<int>> &matrix, int x, int y){
        int ans{}; 
        bool flag{false};
        for(int i = x, j = y; i<= matrix.size() &&  j<= matrix[0].size() && !flag; i++, j++){
            for(int k = j; k - y <= i - x && !flag; k++)
                if(k >= matrix[i].size() || matrix[i][k] == 0)
                    flag = true;
            for(int k = i; k - x <= j - y && !flag; k++)
                if(k >= matrix.size() || matrix[k][j] == 0)
                    flag = true;
            if(!flag)
            ans++;
        }
        return ans;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int ans{};
        for(int i = 0; i< matrix.size(); i++){
            for(int j = 0; j< matrix[i].size(); j++)
                ans += check(matrix, i, j);
        }
        return ans - 1;
    }
};