class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        vector<int> temp;
        auto solve = [&](int i, auto &&self) -> void{
            if(i >= num.size() && temp.size() >=3){
                ans = temp;
                return;
            }
            int n = temp.size();
            long long curr = 0;
            for(int j = i; j < num.size() && ans.empty(); j++){
                curr = curr * 10 + (num[j] - '0');
                if(curr > INT_MAX)
                return;
                if(n == 0 || n == 1 || curr == (long long)temp[n-1] + temp[n-2]){
                    temp.push_back(curr);
                    self(j + 1, self);
                    temp.pop_back();
                }
                if(curr == 0 || (temp.size() >= 2 && (curr >= (long long)temp[n-1] + temp[n-2])))
                return;
            }
        };
        solve(0, solve);
        return ans;
    }
};