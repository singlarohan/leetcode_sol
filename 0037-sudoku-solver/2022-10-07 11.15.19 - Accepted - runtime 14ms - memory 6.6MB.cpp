class Solution {
public:
    void print_sudo(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        //arr[3*(i/3) + j/3][3(i % 3)+(j % 3)]
        vector<vector<char>> ans;
        //count/9 = i; count % 9 = j;
        vector<vector<vector<bool>>> mp(3, vector<vector<bool>> (9, vector<bool> (10, false)));
        //mp[0] -> row, mp[1] -> column, mp[2] = box
        for(int count = 0; count < 81; count++){
            int i = count/9, j = count % 9;
            if(board[i][j] != '.'){
                int k = board[i][j] - '0';
                mp[0][i][k] = true;
                mp[1][j][k] = true;
                mp[2][3*(i/3) + j/3][k] = true;
            }
        }
        auto solve = [&](int count, auto &&self){
            int i = count/9, j = count % 9;
            if(count >= 81){
                // print_sudo(board);
                return true;
            }
            if(board[i][j] != '.')
            return self(count + 1, self);
    
            for(int k = 1; ans.empty() && k <= 9; k++){
                if(!mp[0][i][k] && !mp[1][j][k] && !mp[2][3*(i/3) + j/3][k]){
                    board[i][j] = k + '0';
                    mp[0][i][k] = true;
                    mp[1][j][k] = true;
                    mp[2][3*(i/3) + j/3][k] = true;
                    if(self(count + 1, self))
                        return true;
                    mp[0][i][k] = false;
                    mp[1][j][k] = false;
                    mp[2][3*(i/3) + j/3][k] = false;
                    board[i][j] = '.';
                }
            }
            return false;
        };
        solve(0, solve);
    }
};