class Solution {
public:
    void change_board(vector<string> &board, int i, int j, int n){
        int temp = i;
        while(temp--) board[temp][j] = '.';
        temp = i + 1;
        while(temp < n) board[temp][j] = '.', temp++;
        int temp2 = j;
        while(temp2--) board[i][temp2] = '.';
        temp2 = j + 1;
        while(temp2 < n) board[i][temp2] = '.', temp2++;
        temp = i, temp2 = j;
        while(temp-- && temp2--) board[temp][temp2] = '.';
        temp = i, temp2 = j+1;
        while(temp-- && temp2 < n) board[temp][temp2] = '.', temp2++;
        temp = i + 1, temp2 = j;
        while(temp < n && temp2--) board[temp][temp2] = '.', temp++;
        temp = i + 1, temp2 = j + 1;
        while(temp < n && temp2 < n) board[temp][temp2] = '.', temp++, temp2++;
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '*'));
        
        auto solve = [&](int i, auto &&self){
            if(i == n){
                ans.push_back(temp);
                return;
            }
            vector<string> temp1 = temp;
            for(int j = 0; j < n; j++){
                if(temp[i][j] != '.'){
                    temp[i][j] = 'Q';
                    change_board(temp, i, j, n);
                    self(i + 1, self);
                    temp = temp1;
                }
            }
            return;
        };
        solve(0, solve);
        return ans;
    }
};