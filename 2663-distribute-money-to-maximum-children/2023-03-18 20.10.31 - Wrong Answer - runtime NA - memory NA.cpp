class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        int ans{};
        int i = 0;
        for(i = 0; i < children; i++){
            if(money - 8 < children - i - 1) break;
            else{
                ans++;
                money -= 8;
            }
        }
        if(i == children - 1 && money == 4 && ans > 0) ans--;
        return ans;
    }
};