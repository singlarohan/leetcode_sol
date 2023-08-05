class Solution {
public:
    void place_queen(vector<string> &board, int i, int j, int n){
        // int temp = i;
        // while(temp--) board[temp][j] = '.';
        int temp = i + 1;
        while(temp < n) board[temp][j] = '.', temp++;
        int temp2 = j;
        while(temp2--) board[i][temp2] = '.';
        temp2 = j + 1;
        while(temp2 < n) board[i][temp2] = '.', temp2++;
        // temp = i, temp2 = j;
        // while(temp-- && temp2--) board[temp][temp2] = '.';
        // temp = i, temp2 = j+1;
        // while(temp-- && temp2 < n) board[temp][temp2] = '.', temp2++;
        temp = i + 1, temp2 = j;
        while(temp < n && temp2--) board[temp][temp2] = '.', temp++;
        temp = i + 1, temp2 = j + 1;
        while(temp < n && temp2 < n) board[temp][temp2] = '.', temp++, temp2++;
        return;
    }

    int totalNQueens(int n) {
        // vector<vector<string>> ans;
        int ans{};
        vector<string> temp(n, string(n, '*'));
        
        auto solve = [&](int i, auto &&self){
            if(i == n){
                // ans.push_back(temp);
                ans++;
                return;
            }
            vector<string> temp1 = temp;
            for(int j = 0; j < n; j++){
                if(temp[i][j] != '.'){
                    temp[i][j] = 'Q';
                    place_queen(temp, i, j, n);
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
