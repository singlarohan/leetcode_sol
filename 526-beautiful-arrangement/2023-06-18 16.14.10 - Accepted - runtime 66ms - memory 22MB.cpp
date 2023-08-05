class Solution {
public:
    int countArrangement(int n) {
        unordered_map<int, unordered_map<int, int>> mp;
        //2^n- 1
        int req = pow(2, n) - 1;
        auto solve = [&](int num, int ind, auto &&self){
            if(num == req && ind == n + 1) return 1;
            if(mp.find(num) != mp.end() && mp[num].find(ind) != mp[num].end()) 
                return mp[num][ind];

            int ans{};
            for(int i = 0; i < n; i++){
                if((num & (1 << i)) == 0){
                    int cn = i + 1;
                    if(ind % cn == 0 || cn % ind == 0){
                        num = num | 1 << i;
                        ans += self(num, ind + 1, self);
                        num = num ^ 1 << i;
                    }
                }
            }
            return mp[num][ind] = ans;
        };
        return solve(0, 1, solve);
    }
};