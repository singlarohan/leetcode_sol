class Solution {
public:
    int findSq(int n){
        int temp{};
        while(n != 0){
            temp += pow(n%10, 2);
            n /= 10;
        }
        return temp;
    }
    
    bool isHappy(int n) {
        // unordered_map<int, bool> dp;
        // while(n != 1){
        //     if(dp[n])
        //         return false;
        //     dp[n] = true;
        //     int num{};
        //     while(n != 0){
        //         num += pow(n%10, 2);
        //         n = n/10;
        //     }
        //     n = num;
        // }
        // return true;
        
        //two pointers
        int slow = n;
        int fast = n;
        while(1){
            slow = findSq(slow);
            fast = findSq(findSq(fast));
            if(fast == 1)
                return true;
            if(slow == fast)
                return false;
        }
    }
    
};