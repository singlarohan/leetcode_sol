class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        int ans{};
        for(int i = 0; i < children; i++){
            if(money - 8 < children - i - 1) break;
            else{
                ans++;
                money -= 8;
            }
        }
        if(money == 4) ans--;
        return ans;
    }
};