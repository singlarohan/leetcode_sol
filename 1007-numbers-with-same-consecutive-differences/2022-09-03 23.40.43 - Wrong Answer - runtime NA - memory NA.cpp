class Solution {
public:
    vector<int> ans;
    void solve(int n, int k, string &temp){
        if(temp.size() == n){
            ans.push_back(stoi(temp));
            return;
        }
        if((temp.back() - '0') - k >= 0){
            temp.push_back(((temp.back() - '0') - k) + '0');
            solve(n, k, temp);
            temp.pop_back();
        }
        if((temp.back() - '0') + k < 10){
            temp.push_back(((temp.back() - '0') + k) + '0');
            solve(n, k, temp);
            temp.pop_back();
        }
        return;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        string temp;
        for(int i = 1; i <= 9; i++){
            temp.push_back(i + '0');
            solve(n, k, temp);
            temp.pop_back();
        }
        return ans;
    }
};