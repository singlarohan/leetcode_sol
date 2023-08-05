class Solution {
public:
    double reverse_num(int x){
        double ans{};
        while(x != 0){
            ans = 10*ans + x%10;
            x /= 10;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == reverse_num(x))
            return true;
        return false;
    }
};