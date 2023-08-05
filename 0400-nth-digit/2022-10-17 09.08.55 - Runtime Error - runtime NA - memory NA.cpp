class Solution {
public:
    int findNthDigit(int n) {
        int currN{1}, x = 10;
        int num{}, curr_count{0};
        while(++num){
            if(num == x){
                x *= 10;
                currN++;
            }
            curr_count += currN;
            if(curr_count >= n)
            break;
        }
        curr_count = curr_count - n;
        while(curr_count--)
            num /= 10;
        return num % 10;
    }
};