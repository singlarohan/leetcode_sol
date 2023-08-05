class Solution {
public:
    int minimizeXor(int num1, int num2) {
        if(num2 ==  0) return num1;

        int n = __builtin_popcount(num2);
        
        int ans{};

        for(int i = 30; i >= 0 && n; i--){
            if(((1 << i) & num1) != 0){
                n--;
                ans |= (1 << i);
            }
        }
        for(int i = 0; i < 30 && n; i++){
            if(((1 << i) & num1) == 0){
                n--;
                ans |= 1 << i;
            }
        }
        return ans;
    }
};