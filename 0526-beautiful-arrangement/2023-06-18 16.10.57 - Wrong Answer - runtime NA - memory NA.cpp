class Solution {
public:
    int countArrangement(int n) {
        unordered_map<int, unordered_map<int, int>> mp;
        //2^n- 1
        int req = pow(2, n) - 1;
        auto solve = [&](int num, int ind, auto &&self){
            if(num == req && ind == req) return 1;
            if(mp.find(num) != mp.end() && mp[num].find(ind) != mp[num].end()) 
                return mp[num][ind];

            int ans{};
            for(int i = 0; i < n; i++){
                if((num & (1 << i)) == 0){
                    int cn = i + 1;
                    for(int j = 0; j < n; j++){
                        if((ind & (1 << j)) == 0){ 
                            int ci = j + 1;
                            if(ci % cn == 0 || cn % ci == 0){
                                num = num | 1 << i;
                                ind = ind | 1 << j;
                                ans += self(num, ind, self);
                                num = num ^ 1 << i;
                                ind = ind ^ 1 << j;
                            }
                        }
                    }
                }
            }
            return mp[num][ind] = ans;
        };
        return solve(0, 0, solve);
    }
};