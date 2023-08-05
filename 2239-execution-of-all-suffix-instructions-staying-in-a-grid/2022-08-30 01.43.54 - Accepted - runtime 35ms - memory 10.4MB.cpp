class Solution {
public:
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            int y = startPos[0], x = startPos[1];
            int j = i;
            for(; j < s.size(); j++){
                if(s[j] == 'L'){
                    x--;
                    if(x < 0)
                        break;
                }
                if(s[j] == 'R'){
                    x++;
                    if(x >= n)
                        break;
                }
                if(s[j] == 'U'){
                    y--;
                    if(y < 0)
                        break;
                }
                if(s[j] == 'D'){
                    y++;
                    if(y >= n)
                        break;
                }
            }
            ans.push_back(j - i);
        }
        return ans;
    }
};